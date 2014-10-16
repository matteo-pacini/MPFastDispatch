/////////////////////////////////////////////////////////////////////////////////////
//                                                                                 //
//  The MIT License (MIT)                                                          //
//                                                                                 //
//  Copyright (c) 2014 Matteo Pacini                                               //
//                                                                                 //
//  Permission is hereby granted, free of charge, to any person obtaining a copy   //
//  of this software and associated documentation files (the "Software"), to deal  //
//  in the Software without restriction, including without limitation the rights   //
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      //
//  copies of the Software, and to permit persons to whom the Software is          //
//  furnished to do so, subject to the following conditions:                       //
//                                                                                 //
//  The above copyright notice and this permission notice shall be included in     //
//  all copies or substantial portions of the Software.                            //
//                                                                                 //
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     //
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       //
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    //
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         //
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  //
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN      //
//  THE SOFTWARE.                                                                  //
//                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////

#ifndef __MP_FAST_DISPATCH_H__
#define __MP_FAST_DISPATCH_H__

#define after(SECONDS,BLOCK)                \
    autoreleasepool {}                      \
    dispatch_after(                         \
        dispatch_time(DISPATCH_TIME_NOW,    \
        (int64_t)(SECONDS * NSEC_PER_SEC)), \
        dispatch_get_main_queue(), BLOCK);

#define once(BLOCK)                     \
    autoreleasepool {}                  \
    static dispatch_once_t onceToken;   \
    dispatch_once(&onceToken, BLOCK);

#define mainqueue(BLOCK)                                 \
    autoreleasepool {}                                   \
    dispatch_async(dispatch_get_main_queue(),BLOCK);
    
#define backgroundqueue(BLOCK)                                                              \
    autoreleasepool {}                                                                      \
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND,0),BLOCK);  \
        
#define mainthread(BLOCK)                                 \
    autoreleasepool {}                                    \
    if ([NSThread isMainThread]) BLOCK();                 \
    else dispatch_async(dispatch_get_main_queue(),BLOCK); \

#define sem(TAG, VAL)                         \
    autoreleasepool {}                        \
    __block dispatch_semaphore_t __sem##TAG = \
        dispatch_semaphore_create(VAL);       \

#define sem_wait(TAG, TIMEOUT)                     \
    autoreleasepool {}                             \
    dispatch_semaphore_wait(__sem##TAG, TIMEOUT);  \

#define sem_signal(TAG)                     \
    autoreleasepool {}                      \
    dispatch_semaphore_signal(__sem##TAG);  \

#endif
