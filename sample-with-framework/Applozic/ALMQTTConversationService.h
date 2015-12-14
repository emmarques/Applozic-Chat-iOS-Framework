//
//  ALMQTTConversationService.h
//  Applozic
//
//  Created by Applozic Inc on 11/27/15.
//  Copyright © 2015 applozic Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MQTTSession.h"
#import "ALMessage.h"
#import "ALSyncCallService.h"

@protocol ALMQTTConversationDelegate <NSObject>
-(void) syncCall:(ALMessage *) alMessage;
-(void) delivered:(NSString *) messageKey contactId: (NSString *) contactId;
-(void) updateDeliveryStatusForContact: (NSString *) contactId;
-(void) updateTypingStatus: (NSString *) applicationKey userId: (NSString *) userId status: (BOOL) status;
-(void) mqttConnectionClosed;
@end

@interface ALMQTTConversationService : NSObject <MQTTSessionDelegate>

+(ALMQTTConversationService *)sharedInstance;

@property(nonatomic, weak) ALSyncCallService *alSyncCallService;

-(void) subscribeToConversation;

-(void) unsubscribeToConversation;

-(void) unsubscribeToConversation: (NSString *)userKey;

-(void) sendTypingStatus:(NSString *) applicationKey userID:(NSString *) userId typing: (BOOL) typing;

@property(nonatomic, strong) id<ALMQTTConversationDelegate>mqttConversationDelegate;

@end
