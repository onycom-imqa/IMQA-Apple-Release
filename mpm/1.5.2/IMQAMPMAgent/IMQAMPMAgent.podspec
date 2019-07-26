
Pod::Spec.new do |s|
  s.name             = 'IMQAMPMAgent'
  s.version          = '1.5.2'
  s.summary          = 'MPM SDK for iOS by IMQA'

  s.description      = 'This Framework is MPM SDK for iOS by IMQA'

  s.homepage         = 'http://imqa.io/'
  s.license          = { :type => 'Commercial', :file => 'IMQAMPMAgent/LICENSE' }
  s.author           = { 'Onycom, Inc.' => 'support@imqa.io' }
  s.source           = { :http  => "https://github.com/onycom-imqa/IMQA-Apple-Release/releases/download/1.5.2/IMQAMPMAgent.zip" }

  s.ios.deployment_target = '8.0'
  s.vendored_frameworks = 'IMQAMPMAgent/IMQAMPMAgent.framework'
end
