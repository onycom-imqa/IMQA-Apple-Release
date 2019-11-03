//
//  IMQACrashAgent.h
//  IMQACrashAgent
//
//  Created by Theodore Cha on 2018. 4. 4..
//  Copyright © 2018년 Onycom Inc. All rights reserved.
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
