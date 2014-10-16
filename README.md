#MPFastDispatch

MPFastDispatch is a collection of helper macros for GCD.

#Integration

Add this into your Podfile:

    pod 'MPFastDispatch'

Import the class in your prefix:

    #import <MPFastDispatch.h>

#Macros (so far)

    @once(BLOCK) //"dispatch_once" shorthand
    @after(SECONDS,BLOCK)  //"dispatch_after" shorthand
    @mainqueue(BLOCK)  //Executes a block asynchronously on the main queue
    @backgroundqueue(BLOCK) // Executes a block on the global background queue
    @mainthread(BLOCK)  //Executes a block on the main thread
    
    @sem(TAG,VAL)  //Creates a semaphore named "__sem##TAG" with value "VAL"
    @sem_signal(TAG) //Increments value of semaphore named "__sem##TAG"
    @sem_wait(TAG, TIMEOUT) //Decrements value of semaphore named "__sem##TAG" using timeout "TIMEOUT"

#Comparison

##Dispatch a block asynchronously on the main queue

To dispatch a block on the main queue, you would do...

    dispatch_async(dispatch_get_main_queue(), ^{
        CODE
    });

With **MPFastDispatch** you can do:

    @mainqueue(^{
        CODE
    })

##Dispatch a block asynchronously on the global background queue

To dispatch a block on the background  queue, you would do...

    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND,0), ^{
        CODE
    });

With **MPFastDispatch** you can do:

    @backgroundqueue(^{
        CODE
    })

##Excute a block on the main thread

To excute a block on the main thread, you would do...

    if ([NSThread isMainThread]) {
        CODE
    } else {
        dispatch_async(dispatch_get_main_queue(), ^{
            CODE
        });
    }

With **MPFastDispatch** you can do:

    @mainthread(^{
        CODE
    })

##Dispatch a block once

To dispatch a block once you would do...

    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        CODE
    });

With **MPFastDispatch** you can do:

    @once(^{
        CODE
    })


##Dispatch a block after n seconds

To dispatch a block once you would do...

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW,(int64_t)(SECONDS * NSEC_PER_SEC)), 
        dispatch_get_main_queue(), 
        ^{
            CODE
         });

With **MPFastDispatch** you can do:

    @after(SECONDS,^{
        CODE
    })

##Semaphore shorthands usage

    @backgroundqueue(^{
        
        @sem(One, 0)
        @after(5.0f, ^{
            @sem_signal(One)
        });
        @sem_wait(One, DISPATCH_TIME_FOREVER)
        
        NSLog(@"The end");
        
    });


#Swift

Swift won't be supported as it doesn't include a preprocessor.

#To Do / Contribute

TBW

Fork the repo and send a pull request!

#License

    Copyright (c) 2014 Matteo Pacini
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

