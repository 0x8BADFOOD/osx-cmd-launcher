// Sample code from question: https://developer.apple.com/forums/thread/109283
//
// alterkeys.c
// http://osxbook.com
//
// Complile using the following command line:
//     clang -Wall -o alterkeys alterkeys.c -framework ApplicationServices
//


#include <ApplicationServices/ApplicationServices.h>


// This callback will be invoked every time there is a keystroke.
//
CGEventRef
myCGEventCallback(CGEventTapProxy proxy, CGEventType type,
                  CGEventRef event, void *refcon)
{
    // Paranoid sanity check.
    if ((type != kCGEventKeyDown) && (type != kCGEventKeyUp))
        return event;


    // The incoming keycode.
    CGKeyCode keycode = (CGKeyCode)CGEventGetIntegerValueField(
                                       event, kCGKeyboardEventKeycode);


    // Swap 'a' (keycode=0) and 'z' (keycode=6).
    if (keycode == (CGKeyCode)0)
        keycode = (CGKeyCode)6;
    else if (keycode == (CGKeyCode)6)
        keycode = (CGKeyCode)0;


    // Set the modified keycode field in the event.
    CGEventSetIntegerValueField(
        event, kCGKeyboardEventKeycode, (int64_t)keycode);


    // We must return the event for it to be useful.
    return event;
}


int
main(void)
{
    CGEventMask eventMask = CGEventMaskBit(kCGEventLeftMouseDown) |
                   CGEventMaskBit(kCGEventLeftMouseUp);
    CFMachPortRef eventTap = CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap, 0,
                                eventMask, myCGEventCallback, NULL);
    if (!eventTap) {
        fprintf(stderr, "failed to create event tap\n");
        exit(1);
    }


    // Create a run loop source.
    CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(
                        kCFAllocatorDefault, eventTap, 0);


    // Add to the current run loop.
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource,
                       kCFRunLoopCommonModes);


    // Enable the event tap.
    CGEventTapEnable(eventTap, true);

    printf("It works!\n");

    // Set it all running.
    CFRunLoopRun();


    // In a real program, one would have arranged for cleaning up.


    exit(0);
}
