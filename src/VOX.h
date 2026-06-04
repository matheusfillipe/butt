//
//  VOX.h (minimal ScriptingBridge stub)
//
//  VOX.app ships no public scripting definition on this system, so only the
//  members butt actually reads are declared here. Generated headers (iTunes.h,
//  Spotify.h) come from `sdef <app> | sdp -fh --basename <name>`.
//

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>

@interface VOXApplication : SBApplication
@property (readonly) NSInteger playerState;
@property (copy) NSString *artist;
@property (copy) NSString *track;
@end
