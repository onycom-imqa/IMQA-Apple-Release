
Pod::Spec.new do |s|
    s.name             = 'IMQAMPMAgent'
    s.version          = '2.18.1'
    s.summary          = 'MPM SDK for iOS by IMQA'
  
    s.description      = 'This Framework is MPM SDK for iOS by IMQA'
  
    s.homepage         = 'http://imqa.io/'
    s.author           = { 'Onycom, Inc.' => 'support@imqa.io' }
    s.source           = { :http  => "https://github.com/onycom-imqa/IMQA-Apple-Release/releases/download/2.18.1/IMQAMpmAgent.framework.zip" }
  
    s.ios.deployment_target = '9.0'
    s.vendored_frameworks = 'IMQAMpmAgent.framework'
  end
  