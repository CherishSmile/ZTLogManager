#
# Be sure to run `pod lib lint ZTLogManager.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ZTLogManager'
  s.version          = '1.0.8'
  s.summary          = 'ZTLogManager can display log information within the app'
  s.homepage         = 'https://github.com/CherishSmile/ZTLogManager'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'CherishSmile' => 'misteralvin@yeah.net' }
  s.source           = { :git => 'https://github.com/CherishSmile/ZTLogManager.git', :tag => s.version.to_s }
  s.ios.deployment_target = '10.0'
  s.requires_arc = true
  s.pod_target_xcconfig = {
    'VALID_ARCHS' => 'x86_64 armv7 arm64'
  }
  s.vendored_frameworks = 'ZTLogManager/ZTLogManager.framework'
  s.resource = 'ZTLogManager/ZTLogManager.bundle'

end
