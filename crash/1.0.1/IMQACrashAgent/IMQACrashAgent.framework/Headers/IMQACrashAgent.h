//
//  IMQACrashAgent.h
//  IMQACrashAgent
//
//  Created by Theodore Cha on 08/06/2018.
//  Copyright © 2018 Theodore Cha. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IMQAConfiguration.h"
#import "IMQAMetaData.h"

//! Project version number for Sentry.
FOUNDATION_EXPORT double IMQACrashAgentVersionNumber;

//! Project version string for Sentry.
FOUNDATION_EXPORT const unsigned char IMQACrashAgentVersionString[];


static NSString *_Nonnull const IMQACrashSeverityError = @"error";
static NSString *_Nonnull const IMQACrashSeverityWarning = @"warning";
static NSString *_Nonnull const IMQACrashSeverityInfo = @"info";

@interface IMQACrashAgent : NSObject

+ (IMQAConfiguration *_Nullable)configuration;

+ (void)startIMQAWithApiKey:(NSString *_Nonnull)apiKey;

+ (void)startIMQAWithConfiguration:
(IMQAConfiguration *_Nonnull)configuration;

+ (void)notify:(NSException *_Nonnull)exception;

+ (void)notify:(NSException *_Nonnull)exception
         block:(IMQANotifyBlock _Nullable)block;

+ (void)notifyError:(NSError *_Nonnull)error;

+ (void)notifyError:(NSError *_Nonnull)error
              block:(IMQANotifyBlock _Nullable)block;

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
                       block:(IMQANotifyBlock _Nullable)block;

+ (void)addAttribute:(NSString *_Nonnull)attributeName
           withValue:(id _Nullable)value
       toTabWithName:(NSString *_Nonnull)tabName;

+ (void)clearTabWithName:(NSString *_Nonnull)tabName;

+ (void)leaveBreadcrumbWithMessage:(NSString *_Nonnull)message;

+ (void)leaveBreadcrumbWithBlock:
(void (^_Nonnull)(IMQABreadcrumb *_Nonnull))block;

+ (void)leaveBreadcrumbForNotificationName:(NSString *_Nonnull)notificationName;

+ (void)setBreadcrumbCapacity:(NSUInteger)capacity;

+ (void)clearBreadcrumbs;

+ (NSDateFormatter *_Nonnull)payloadDateFormatter;

+ (void)setSuspendThreadsForUserReported:(BOOL)suspendThreadsForUserReported;

+ (void)setReportWhenDebuggerIsAttached:(BOOL)reportWhenDebuggerIsAttached;

+ (void)setThreadTracingEnabled:(BOOL)threadTracingEnabled;

+ (void)setWriteBinaryImagesForUserReported:(BOOL)writeBinaryImagesForUserReported;

+ (void)startSession;

@end
