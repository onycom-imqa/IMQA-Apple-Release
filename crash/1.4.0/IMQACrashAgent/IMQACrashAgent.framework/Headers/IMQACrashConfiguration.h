//
//  IMQACrashConfiguration.h
//  IMQACrashAgent
//
//  Created by Theodore Cha on 2018. 4. 4..
//  Copyright © 2018년 Onycom Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "IMQA_KSCrashReportWriter.h"
#import "IMQACrashBreadcrumb.h"
#import "IMQACrashCrashReport.h"
#import "IMQACrashMetaData.h"

@class IMQACrashBreadcrumbs;
@class IMQACrashUser;

typedef void (^IMQACrashNotifyBlock)(IMQACrashCrashReport *_Nonnull report);

typedef bool (^IMQACrashBeforeSendBlock)(NSDictionary *_Nonnull rawEventData,
                                       IMQACrashCrashReport *_Nonnull reports);

typedef NSDictionary *_Nullable (^IMQACrashBeforeNotifyHook)(
    NSArray *_Nonnull rawEventReports, NSDictionary *_Nonnull report);

@interface IMQACrashConfiguration : NSObject

@property(readwrite, retain, nullable) NSString *apiKey;

@property(readwrite, retain, nullable) NSURL *notifyURL;

@property(readwrite, retain, nullable) NSString *releaseStage;

@property(readwrite, retain, nullable) NSArray *notifyReleaseStages;

@property(readwrite, retain, nullable) NSString *context;

@property(readwrite, retain, nullable) NSString *appVersion;

@property(readwrite, strong, nonnull) NSURLSession *session;

@property(retain, nullable) IMQACrashUser *currentUser;

@property(readwrite, retain, nullable) IMQACrashMetaData *metaData;

@property(readwrite, retain, nullable) IMQACrashMetaData *config;

@property(readonly, strong, nullable)
IMQACrashBreadcrumbs *breadcrumbs;

@property(readwrite) BOOL automaticallyCollectBreadcrumbs;

@property(readonly, strong, nullable)
    NSArray<IMQACrashBeforeSendBlock> *beforeSendBlocks;

@property void (*_Nullable onCrashHandler)
    (const IMQA_KSCrashReportWriter *_Nonnull writer);

@property BOOL autoNotify;

@property BOOL shouldAutoCaptureSessions;


@property(readwrite, retain, nullable) NSURL *sessionURL;

- (void)setUser:(NSString *_Nullable)userId
       withName:(NSString *_Nullable)name
       andEmail:(NSString *_Nullable)email;

- (void)addBeforeSendBlock:(IMQACrashBeforeSendBlock _Nonnull)block;

- (void)clearBeforeSendBlocks;

- (BOOL)shouldSendReports;

- (void)addBeforeNotifyHook:(IMQACrashBeforeNotifyHook _Nonnull)hook
    __deprecated_msg("Use addBeforeSendBlock: instead.");

@property(readonly, strong, nullable)
    NSArray *beforeNotifyHooks __deprecated_msg("Use beforeNotify instead.");

- (NSDictionary *_Nonnull)errorApiHeaders;
- (NSDictionary *_Nonnull)sessionApiHeaders;

@property(retain, nullable) NSString *codeBundleId;
@property(retain, nullable) NSString *notifierType;

- (BOOL)hasValidApiKey;

@end
