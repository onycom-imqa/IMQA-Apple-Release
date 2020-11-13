
Pod::Spec.new do |s|
    s.name             = 'IMQAMPMAgent'
    s.version          = '2.19.0'
    s.summary          = 'MPM SDK for iOS by IMQA'
  
    s.description      = 'This Framework is MPM SDK for iOS by IMQA'
  
    s.homepage         = 'http://imqa.io/'
    s.author           = { 'Onycom, Inc.' => 'support@imqa.io' }
    s.source           = { :http  => "https://github.com/onycom-imqa/IMQA-Apple-Release/releases/download/2.19.0/IMQAMpmAgent.framework.zip" }

    s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
    s.ios.deployment_target = '9.0'
    s.vendored_frameworks = 'IMQAMpmAgent.framework'
  end
  
