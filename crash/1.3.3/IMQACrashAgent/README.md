# IMQA Crash Integration for Apple

IMQA Crash 를 Apple 프로젝트에 추가하면, Objective-C 및 Swift 로 개발한 앱에서 발생하는 충돌을 자동으로 캡처하여 보여드립니다.

IMQA Crash를 처음 사용하시나요? [지금 계정을 만들어보세요.](https://imqa.io)


## 설치 (Installation) 

IMQA Crash SDK는 CocoaPods 또는 직접 추가하여 설치할 수 있습니다. Swift와 Objective-C 모두 같은 방법으로 설치합니다.

IMQA Crash는 CocoaPods으로 설치하는 것을 권장합니다.

### CocoaPods

Podfile 에 IMQACrash 를 추가해주세요.

```
pod 'IMQACrash'
```

반드시 Podfile 업데이트 한 후 Pod install을 해주시길 바랍니다.

### 직접 추가

1. 다음 링크를 통해 원하시는 버전의 파일을 다운로드 받아주세요.
2. 압축을 푼 후 framework 파일을 프로젝트에 옮겨주세요.
3. 옮긴 후 Link Framework or Library 에 옮긴 프레임워크를 추가 해주세요.


## Swift 기본 설정 (Basic Configuration for Swift) 

1. AppDeligate.swift 에서 IMQACrash 헤더를 가지고 옵니다.

```swift
import IMQACrash
```

2. application:didFinishLaunchingWithOptions: 에 IMQACrash를 초기화 해 줍니다.
PROJECT_KEY 는 IMQA 사이트에서 프로젝트를 생성한 후 발급 받으실 수 있습니다.

```swift
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
     
    IMQACrash.startIMQA(withApiKey: "<PROJECT_KEY>")
        
    return true
}
```


## Objective-C 기본 설정 (Basic Configuration for Objective-C) 

1. AppDeligate.m 에서 IMQACrash 헤더를 가지고 옵니다.

```objc
#import <IMQACrash/IMQACrash.h>
```

2. application:didFinishLaunchingWithOptions: 에 IMQACrash를 초기화 해 줍니다.
PROJECT_KEY 는 IMQA 사이트에서 프로젝트를 생성한 후 발급 받으실 수 있습니다.

```objc
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    [IMQACrash startIMQAWithApiKey:@"<PROJECT_KEY>"];
    
    return YES;
}
```
