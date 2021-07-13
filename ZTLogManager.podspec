#
# Be sure to run `pod lib lint ZTLogManager.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ZTLogManager'
  s.version          = '1.0.3'
  s.summary          = 'ZTLogManager can display log information within the app'
  s.homepage         = 'https://github.com/CherishSmile/ZTLogManager'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'CherishSmile' => 'misteralvin@yeah.net' }
  s.source           = { :git => 'https://github.com/CherishSmile/ZTLogManager.git', :tag => s.version.to_s }
  s.ios.deployment_target = '10.0'
  s.requires_arc = true


  s.source_files = 'ZTLogManager/ZTLogManager.framework/Headers/*.{h}'
  s.vendored_frameworks = 'ZTLogManager/ZTLogManager.framework'
  s.public_header_files = 'ZTLogManager/ZTLogManager.framework/Headers/*.{h}'
  s.resource = 'ZTLogManager/ZTLogManager.framework/Resource.bundle'

  # s.resource_bundles = {
  #   'ZTLogManager' => ['ZTLogManager/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
