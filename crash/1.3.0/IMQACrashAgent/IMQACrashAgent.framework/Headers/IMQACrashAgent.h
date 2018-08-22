//
//  IMQACrashAgent.h
//
//  Created by Conrad Irwin on 2014-10-01.
//
//  Copyright (c) 2014 Bugsnag, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall remain in place
// in this source code.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
#import <Foundation/Foundation.h>

#import "IMQACrashConfiguration.h"
#import "IMQACrashMetaData.h"

static NSString *_Nonnull const IMQACrashSeverityError = @"error";
static NSString *_Nonnull const IMQACrashSeverityWarning = @"warning";
static NSString *_Nonnull const IMQACrashSeverityInfo = @"info";

@interface IMQACrashAgent : NSObject

+ (IMQACrashConfiguration *_Nullable)configuration;

+ (void)startIMQACrashWithApiKey:(NSString *_Nonnull)apiKey;

+ (void)startIMQACrashWithConfiguration:
(IMQACrashConfiguration *_Nonnull)configuration;

+ (void)notify:(NSException *_Nonnull)exception;

+ (void)notify:(NSException *_Nonnull)exception
         block:(IMQACrashNotifyBlock _Nullable)block;

+ (void)notifyError:(NSError *_Nonnull)error;

+ (void)notifyError:(NSError *_Nonnull)error
              block:(IMQACrashNotifyBlock _Nullable)block;

+ (void)notify:(NSException *_Nonnull)exception
      withData:(NSDictionary *_Nullable)metaData
__deprecated_msg("Use notify:block: instead and add the metadata to the "
                 "report directly.");

+ (void)notify:(NSException *_Nonnull)exception
      withData:(NSDictionary *_Nullable)metaData
    atSeverity:(NSString *_Nullable)severity
__deprecated_msg("Use notify:block: instead and add the metadata and "
                 "severity to the report directly.");

+ (void)internalClientNotify:(NSException *_Nonnull)exception
                    withData:(NSDictionary *_Nullable)metaData
                       block:(IMQACrashNotifyBlock _Nullable)block;

+ (void)addAttribute:(NSString *_Nonnull)attributeName
           withValue:(id _Nullable)value
       toTabWithName:(NSString *_Nonnull)tabName;

+ (void)clearTabWithName:(NSString *_Nonnull)tabName;

+ (void)leaveBreadcrumbWithMessage:(NSString *_Nonnull)message;

+ (void)leaveBreadcrumbWithBlock:
(void (^_Nonnull)(IMQACrashBreadcrumb *_Nonnull))block;

+ (void)leaveBreadcrumbForNotificationName:(NSString *_Nonnull)notificationName;

+ (void)setBreadcrumbCapacity:(NSUInteger)capacity;

+ (void)clearBreadcrumbs;

+ (NSDateFormatter *_Nonnull)payloadDateFormatter;

+ (void)setSuspendThreadsForUserReported:(BOOL)suspendThreadsForUserReported;
+ (void)setReportWhenDebuggerIsAttached:(BOOL)reportWhenDebuggerIsAttached;
+ (void)setThreadTracingEnabled:(BOOL)threadTracingEnabled;
+ (void)setWriteBinaryImagesForUserReported:
(BOOL)writeBinaryImagesForUserReported;

+ (void)startSession;

@end
