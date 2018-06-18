#
# Be sure to run `pod lib lint IMQACrash.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'IMQACrashAgent'
  s.version          = '1.0.1'
  s.summary          = 'Crash Report SDK for iOS by IMQA'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = 'This Framework is Crash Report SDK for iOS by IMQA'

  s.homepage         = 'http://imqa.io/'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'Commercial', :file => 'IMQACrashAgent/LICENSE' }
  s.author           = { 'Onycom, Inc.' => 'support@imqa.io' }
  s.source           = { :http  => "https://github.com/onycom-imqa/IMQA-Crash-Cocoa-Release/releases/download/18.6.11/IMQACrashAgent.zip" }

  s.ios.deployment_target = '9.0'

  s.source_files = 'IMQACrashAgent/IMQACrashAgent.framework/**/*.h'
  s.vendored_frameworks = 'IMQACrashAgent/IMQACrashAgent.framework'
  s.preserve_paths = 'IMQACrashAgent/*.framework'
  
  # s.resource_bundles = {
  #   'IMQACrash' => ['IMQACrash/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  s.frameworks = 'Foundation', 'SystemConfiguration'
  s.libraries = 'c++', 'z'
  # s.dependency 'AFNetworking', '~> 2.3'
end
