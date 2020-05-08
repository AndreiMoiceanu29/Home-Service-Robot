
(cl:in-package :asdf)

(defsystem "ball_chaser-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ObjectFound" :depends-on ("_package_ObjectFound"))
    (:file "_package_ObjectFound" :depends-on ("_package"))
  ))