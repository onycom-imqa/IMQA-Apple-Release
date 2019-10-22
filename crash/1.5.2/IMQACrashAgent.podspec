
Pod::Spec.new do |s|
  s.name             = 'IMQACrashAgent'
  s.version          = '1.5.2'
  s.summary          = 'Crash Report SDK for iOS by IMQA'

  s.description      = 'This Framework is Crash Report SDK for iOS by IMQA'

  s.homepage         = 'http://imqa.io/'
  s.license          = { :type => 'Commercial', :file => 'IMQACrashAgent/LICENSE' }
  s.author           = { 'Onycom, Inc.' => 'support@imqa.io' }
  s.source           = { :http  => "https://github.com/onycom-imqa/IMQA-Apple-Release/releases/download/1.5.2/IMQACrashAgent.zip" }

  s.ios.deployment_target = '8.0'

  s.source_files = 'IMQACrashAgent/IMQACrashAgent.framework/**/*.h'
  s.vendored_frameworks = 'IMQACrashAgent/IMQACrashAgent.framework'
  s.preserve_paths = 'IMQACrashAgent/*.framework'

  s.frameworks = 'Foundation', 'SystemConfiguration'
  s.libraries = 'c++', 'z'
end
