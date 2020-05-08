; Auto-generated. Do not edit!


(cl:in-package ball_chaser-msg)


;//! \htmlinclude ObjectFound.msg.html

(cl:defclass <ObjectFound> (roslisp-msg-protocol:ros-message)
  ((is_found
    :reader is_found
    :initarg :is_found
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ObjectFound (<ObjectFound>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ObjectFound>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ObjectFound)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ball_chaser-msg:<ObjectFound> is deprecated: use ball_chaser-msg:ObjectFound instead.")))

(cl:ensure-generic-function 'is_found-val :lambda-list '(m))
(cl:defmethod is_found-val ((m <ObjectFound>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ball_chaser-msg:is_found-val is deprecated.  Use ball_chaser-msg:is_found instead.")
  (is_found m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ObjectFound>) ostream)
  "Serializes a message object of type '<ObjectFound>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'is_found) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ObjectFound>) istream)
  "Deserializes a message object of type '<ObjectFound>"
    (cl:setf (cl:slot-value msg 'is_found) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ObjectFound>)))
  "Returns string type for a message object of type '<ObjectFound>"
  "ball_chaser/ObjectFound")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ObjectFound)))
  "Returns string type for a message object of type 'ObjectFound"
  "ball_chaser/ObjectFound")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ObjectFound>)))
  "Returns md5sum for a message object of type '<ObjectFound>"
  "8adcb5649ca708386016da412c13201d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ObjectFound)))
  "Returns md5sum for a message object of type 'ObjectFound"
  "8adcb5649ca708386016da412c13201d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ObjectFound>)))
  "Returns full string definition for message of type '<ObjectFound>"
  (cl:format cl:nil "bool is_found~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ObjectFound)))
  "Returns full string definition for message of type 'ObjectFound"
  (cl:format cl:nil "bool is_found~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ObjectFound>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ObjectFound>))
  "Converts a ROS message object to a list"
  (cl:list 'ObjectFound
    (cl:cons ':is_found (is_found msg))
))
