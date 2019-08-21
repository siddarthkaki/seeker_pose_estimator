// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pose.proto

#ifndef PROTOBUF_pose_2eproto__INCLUDED
#define PROTOBUF_pose_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace ProtoPose {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_pose_2eproto();
void protobuf_AssignDesc_pose_2eproto();
void protobuf_ShutdownFile_pose_2eproto();

class Attitude;
class Pose;
class Position;

// ===================================================================

class Position : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ProtoPose.Position) */ {
 public:
  Position();
  virtual ~Position();

  Position(const Position& from);

  inline Position& operator=(const Position& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Position& default_instance();

  void Swap(Position* other);

  // implements Message ----------------------------------------------

  inline Position* New() const { return New(NULL); }

  Position* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Position& from);
  void MergeFrom(const Position& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Position* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional double x = 1;
  void clear_x();
  static const int kXFieldNumber = 1;
  double x() const;
  void set_x(double value);

  // optional double y = 2;
  void clear_y();
  static const int kYFieldNumber = 2;
  double y() const;
  void set_y(double value);

  // optional double z = 3;
  void clear_z();
  static const int kZFieldNumber = 3;
  double z() const;
  void set_z(double value);

  // @@protoc_insertion_point(class_scope:ProtoPose.Position)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  double x_;
  double y_;
  double z_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_pose_2eproto();
  friend void protobuf_AssignDesc_pose_2eproto();
  friend void protobuf_ShutdownFile_pose_2eproto();

  void InitAsDefaultInstance();
  static Position* default_instance_;
};
// -------------------------------------------------------------------

class Attitude : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ProtoPose.Attitude) */ {
 public:
  Attitude();
  virtual ~Attitude();

  Attitude(const Attitude& from);

  inline Attitude& operator=(const Attitude& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Attitude& default_instance();

  void Swap(Attitude* other);

  // implements Message ----------------------------------------------

  inline Attitude* New() const { return New(NULL); }

  Attitude* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Attitude& from);
  void MergeFrom(const Attitude& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Attitude* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional double qw = 1;
  void clear_qw();
  static const int kQwFieldNumber = 1;
  double qw() const;
  void set_qw(double value);

  // optional double qx = 2;
  void clear_qx();
  static const int kQxFieldNumber = 2;
  double qx() const;
  void set_qx(double value);

  // optional double qy = 3;
  void clear_qy();
  static const int kQyFieldNumber = 3;
  double qy() const;
  void set_qy(double value);

  // optional double qz = 4;
  void clear_qz();
  static const int kQzFieldNumber = 4;
  double qz() const;
  void set_qz(double value);

  // @@protoc_insertion_point(class_scope:ProtoPose.Attitude)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  double qw_;
  double qx_;
  double qy_;
  double qz_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_pose_2eproto();
  friend void protobuf_AssignDesc_pose_2eproto();
  friend void protobuf_ShutdownFile_pose_2eproto();

  void InitAsDefaultInstance();
  static Attitude* default_instance_;
};
// -------------------------------------------------------------------

class Pose : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ProtoPose.Pose) */ {
 public:
  Pose();
  virtual ~Pose();

  Pose(const Pose& from);

  inline Pose& operator=(const Pose& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Pose& default_instance();

  void Swap(Pose* other);

  // implements Message ----------------------------------------------

  inline Pose* New() const { return New(NULL); }

  Pose* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Pose& from);
  void MergeFrom(const Pose& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Pose* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .ProtoPose.Position pos = 1;
  bool has_pos() const;
  void clear_pos();
  static const int kPosFieldNumber = 1;
  const ::ProtoPose::Position& pos() const;
  ::ProtoPose::Position* mutable_pos();
  ::ProtoPose::Position* release_pos();
  void set_allocated_pos(::ProtoPose::Position* pos);

  // optional .ProtoPose.Attitude att = 2;
  bool has_att() const;
  void clear_att();
  static const int kAttFieldNumber = 2;
  const ::ProtoPose::Attitude& att() const;
  ::ProtoPose::Attitude* mutable_att();
  ::ProtoPose::Attitude* release_att();
  void set_allocated_att(::ProtoPose::Attitude* att);

  // optional double time_stamp = 3;
  void clear_time_stamp();
  static const int kTimeStampFieldNumber = 3;
  double time_stamp() const;
  void set_time_stamp(double value);

  // @@protoc_insertion_point(class_scope:ProtoPose.Pose)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::ProtoPose::Position* pos_;
  ::ProtoPose::Attitude* att_;
  double time_stamp_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_pose_2eproto();
  friend void protobuf_AssignDesc_pose_2eproto();
  friend void protobuf_ShutdownFile_pose_2eproto();

  void InitAsDefaultInstance();
  static Pose* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Position

// optional double x = 1;
inline void Position::clear_x() {
  x_ = 0;
}
inline double Position::x() const {
  // @@protoc_insertion_point(field_get:ProtoPose.Position.x)
  return x_;
}
inline void Position::set_x(double value) {
  
  x_ = value;
  // @@protoc_insertion_point(field_set:ProtoPose.Position.x)
}

// optional double y = 2;
inline void Position::clear_y() {
  y_ = 0;
}
inline double Position::y() const {
  // @@protoc_insertion_point(field_get:ProtoPose.Position.y)
  return y_;
}
inline void Position::set_y(double value) {
  
  y_ = value;
  // @@protoc_insertion_point(field_set:ProtoPose.Position.y)
}

// optional double z = 3;
inline void Position::clear_z() {
  z_ = 0;
}
inline double Position::z() const {
  // @@protoc_insertion_point(field_get:ProtoPose.Position.z)
  return z_;
}
inline void Position::set_z(double value) {
  
  z_ = value;
  // @@protoc_insertion_point(field_set:ProtoPose.Position.z)
}

// -------------------------------------------------------------------

// Attitude

// optional double qw = 1;
inline void Attitude::clear_qw() {
  qw_ = 0;
}
inline double Attitude::qw() const {
  // @@protoc_insertion_point(field_get:ProtoPose.Attitude.qw)
  return qw_;
}
inline void Attitude::set_qw(double value) {
  
  qw_ = value;
  // @@protoc_insertion_point(field_set:ProtoPose.Attitude.qw)
}

// optional double qx = 2;
inline void Attitude::clear_qx() {
  qx_ = 0;
}
inline double Attitude::qx() const {
  // @@protoc_insertion_point(field_get:ProtoPose.Attitude.qx)
  return qx_;
}
inline void Attitude::set_qx(double value) {
  
  qx_ = value;
  // @@protoc_insertion_point(field_set:ProtoPose.Attitude.qx)
}

// optional double qy = 3;
inline void Attitude::clear_qy() {
  qy_ = 0;
}
inline double Attitude::qy() const {
  // @@protoc_insertion_point(field_get:ProtoPose.Attitude.qy)
  return qy_;
}
inline void Attitude::set_qy(double value) {
  
  qy_ = value;
  // @@protoc_insertion_point(field_set:ProtoPose.Attitude.qy)
}

// optional double qz = 4;
inline void Attitude::clear_qz() {
  qz_ = 0;
}
inline double Attitude::qz() const {
  // @@protoc_insertion_point(field_get:ProtoPose.Attitude.qz)
  return qz_;
}
inline void Attitude::set_qz(double value) {
  
  qz_ = value;
  // @@protoc_insertion_point(field_set:ProtoPose.Attitude.qz)
}

// -------------------------------------------------------------------

// Pose

// optional .ProtoPose.Position pos = 1;
inline bool Pose::has_pos() const {
  return !_is_default_instance_ && pos_ != NULL;
}
inline void Pose::clear_pos() {
  if (GetArenaNoVirtual() == NULL && pos_ != NULL) delete pos_;
  pos_ = NULL;
}
inline const ::ProtoPose::Position& Pose::pos() const {
  // @@protoc_insertion_point(field_get:ProtoPose.Pose.pos)
  return pos_ != NULL ? *pos_ : *default_instance_->pos_;
}
inline ::ProtoPose::Position* Pose::mutable_pos() {
  
  if (pos_ == NULL) {
    pos_ = new ::ProtoPose::Position;
  }
  // @@protoc_insertion_point(field_mutable:ProtoPose.Pose.pos)
  return pos_;
}
inline ::ProtoPose::Position* Pose::release_pos() {
  // @@protoc_insertion_point(field_release:ProtoPose.Pose.pos)
  
  ::ProtoPose::Position* temp = pos_;
  pos_ = NULL;
  return temp;
}
inline void Pose::set_allocated_pos(::ProtoPose::Position* pos) {
  delete pos_;
  pos_ = pos;
  if (pos) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:ProtoPose.Pose.pos)
}

// optional .ProtoPose.Attitude att = 2;
inline bool Pose::has_att() const {
  return !_is_default_instance_ && att_ != NULL;
}
inline void Pose::clear_att() {
  if (GetArenaNoVirtual() == NULL && att_ != NULL) delete att_;
  att_ = NULL;
}
inline const ::ProtoPose::Attitude& Pose::att() const {
  // @@protoc_insertion_point(field_get:ProtoPose.Pose.att)
  return att_ != NULL ? *att_ : *default_instance_->att_;
}
inline ::ProtoPose::Attitude* Pose::mutable_att() {
  
  if (att_ == NULL) {
    att_ = new ::ProtoPose::Attitude;
  }
  // @@protoc_insertion_point(field_mutable:ProtoPose.Pose.att)
  return att_;
}
inline ::ProtoPose::Attitude* Pose::release_att() {
  // @@protoc_insertion_point(field_release:ProtoPose.Pose.att)
  
  ::ProtoPose::Attitude* temp = att_;
  att_ = NULL;
  return temp;
}
inline void Pose::set_allocated_att(::ProtoPose::Attitude* att) {
  delete att_;
  att_ = att;
  if (att) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:ProtoPose.Pose.att)
}

// optional double time_stamp = 3;
inline void Pose::clear_time_stamp() {
  time_stamp_ = 0;
}
inline double Pose::time_stamp() const {
  // @@protoc_insertion_point(field_get:ProtoPose.Pose.time_stamp)
  return time_stamp_;
}
inline void Pose::set_time_stamp(double value) {
  
  time_stamp_ = value;
  // @@protoc_insertion_point(field_set:ProtoPose.Pose.time_stamp)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace ProtoPose

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_pose_2eproto__INCLUDED