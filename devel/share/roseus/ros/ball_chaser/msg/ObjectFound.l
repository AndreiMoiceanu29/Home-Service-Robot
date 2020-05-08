;; Auto-generated. Do not edit!


(when (boundp 'ball_chaser::ObjectFound)
  (if (not (find-package "BALL_CHASER"))
    (make-package "BALL_CHASER"))
  (shadow 'ObjectFound (find-package "BALL_CHASER")))
(unless (find-package "BALL_CHASER::OBJECTFOUND")
  (make-package "BALL_CHASER::OBJECTFOUND"))

(in-package "ROS")
;;//! \htmlinclude ObjectFound.msg.html


(defclass ball_chaser::ObjectFound
  :super ros::object
  :slots (_is_found ))

(defmethod ball_chaser::ObjectFound
  (:init
   (&key
    ((:is_found __is_found) nil)
    )
   (send-super :init)
   (setq _is_found __is_found)
   self)
  (:is_found
   (&optional __is_found)
   (if __is_found (setq _is_found __is_found)) _is_found)
  (:serialization-length
   ()
   (+
    ;; bool _is_found
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _is_found
       (if _is_found (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _is_found
     (setq _is_found (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get ball_chaser::ObjectFound :md5sum-) "8adcb5649ca708386016da412c13201d")
(setf (get ball_chaser::ObjectFound :datatype-) "ball_chaser/ObjectFound")
(setf (get ball_chaser::ObjectFound :definition-)
      "bool is_found
")



(provide :ball_chaser/ObjectFound "8adcb5649ca708386016da412c13201d")


