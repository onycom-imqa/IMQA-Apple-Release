<p align="center">
    <a href="https://sentry.io" target="_blank" align="center">
        <img src="/logo.png" width="280">
    </a>
  
</p>

# IMQA Cocoa Release Center


| Product Name   | LTS Version | Latest Version |
|----------------|-------------|----------------|
| IMQACrashAgent | 1.0.0       | 1.1.0          |
| IMQAMpmAgent   | N/A         | N/A            |

</br>


## IMQACrashAgent Release Note (KR)

### (Latest Version) 1.1.0 

- Swift 4.0 이상 버전을 위한 보안 패치를 진행하였습니다. 
- 일부 기기에서 작동하지 않는 버그를 수정하였습니다. 
- 수집 방법에 있어서 추후 MPM 과 동기화 하기 위한 작업으로 수정이 되었습니다. 
- 일부 OS 에서 데이터 수집에 병목이 생기는 버그를 수정하였습니다. 

> 2018.06.19 ~ 2018.07.23 까지는 하위 버전을 사용해도 큰 이상은 없으나, 
> 2018.07.24 이후 부터는 1.1.0 이하 버전은 지원하지 않아 수집을 하지 않습니다. 


### 1.0.1 

- 수집서버 URL 변경이 되었습니다. 
- HTTP에서 HTTPS 로 수집서버 URL 통신 방식이 변경되었습니다. 

### (LTS Version) 1.0.0

- IMQACrash 에서 IMQACrashAgent 로 이름이 변경되었습니다. 
- 이름과 프로젝트가 변경됨에 따라 버전 1.0.0 으로 시작합니다. 

</br>

## LICENSE

All other components of this product are: Copyright (c) 2018 Onycom, Inc. All rights reserved.

Certain inventions disclosed in this file may be claimed within patents owned or patent applications
filed by Onycom, Inc. or third parties. Subject to the terms of this notice, Onycom grants you
a nonexclusive, nontransferable license, without the right to sublicense, to (a) install and execute
one copy of these files on any number of workstations owned or controlled by you and (b) distribute
verbatim copies of these files to third parties. As a condition to the foregoing grant, you must
provide this notice along with each copy you distribute and you must not remove, alter, or obscure
this notice.

All other use, reproduction, modification, distribution, or other exploitation of these
files is strictly prohibited, except as may be set forth in a separate written license agreement
between you and Onycom. The terms of any such license agreement will control over this notice. The
license stated above will be automatically terminated and revoked if you exceed its scope or violate
any of the terms of this notice.

This License does not grant permission to use the trade names, trademarks, service marks, or product
names of Onycom, except as required for reasonable and customary use in describing the origin of
this file and reproducing the content of this notice. You may not mark or brand this file with any
trade name, trademarks, service marks, or product names other than the original brand (if any) provided
by Onycom.

Unless otherwise expressly agreed by Onycom in a separate written license agreement, these files
are provided AS IS, WITHOUT WARRANTY OF ANY KIND, including without any implied warranties of
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE, or NON-INFRINGEMENT. As a condition to your
use of these files, you are solely responsible for such use. Onycom will have no liability to you
for direct, indirect, consequential, incidental, special, or punitive damages or for lost profits or
data.

## OSS Notice

#### KSCrash 

Copyright (c) 2012 Karl Stenerud

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in the documentation of any redistributions of the template files themselves (but not in projects built using the templates).

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#### Bugsnag 

Copyright (c) 2012 Bugsnag, https://bugsnag.com/

Permission is hereby granted, free of charge, to any person obtaining 
a copy of this software and associated documentation files (the "Software"), 
to deal in the Software without restriction, including without limitation 
the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the Software 
is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
THE SOFTWARE.
