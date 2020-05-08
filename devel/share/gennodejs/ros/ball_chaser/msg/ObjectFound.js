// Auto-generated. Do not edit!

// (in-package ball_chaser.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ObjectFound {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.is_found = null;
    }
    else {
      if (initObj.hasOwnProperty('is_found')) {
        this.is_found = initObj.is_found
      }
      else {
        this.is_found = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ObjectFound
    // Serialize message field [is_found]
    bufferOffset = _serializer.bool(obj.is_found, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ObjectFound
    let len;
    let data = new ObjectFound(null);
    // Deserialize message field [is_found]
    data.is_found = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ball_chaser/ObjectFound';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8adcb5649ca708386016da412c13201d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool is_found
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ObjectFound(null);
    if (msg.is_found !== undefined) {
      resolved.is_found = msg.is_found;
    }
    else {
      resolved.is_found = false
    }

    return resolved;
    }
};

module.exports = ObjectFound;
