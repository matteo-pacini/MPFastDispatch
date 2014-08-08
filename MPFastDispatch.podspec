Pod::Spec.new do |s|

  s.ios.deployment_target = '4.0'
  s.osx.deployment_target = '10.6'

  s.name         = "MPFastDispatch"
  s.version      = "0.1.1"
  s.summary      = "Useful GCD shorthands"

  s.description  = <<-DESC
                   Useful GCD shorthands.
                   DESC

  s.homepage     = "http://github.com/Zi0P4tch0/MPFastDispatch"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author             = { "Matteo Pacini" => "ispeakprogramming@gmail.com" }
  s.social_media_url   = "http://twitter.com/Zi0P4tch0"
  
  s.source       = { :git => "https://github.com/Zi0P4tch0/MPFastDispatch.git", :tag => "0.1.0" }
  s.source_files  = "*.{h,m}"
  s.requires_arc = true
  s.framework = 'Foundation'

end