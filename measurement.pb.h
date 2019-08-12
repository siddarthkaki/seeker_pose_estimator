// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: measurement.proto

#ifndef PROTOBUF_measurement_2eproto__INCLUDED
#define PROTOBUF_measurement_2eproto__INCLUDED

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
#include "pose.pb.h"
// @@protoc_insertion_point(includes)

namespace Proto {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_measurement_2eproto();
void protobuf_AssignDesc_measurement_2eproto();
void protobuf_ShutdownFile_measurement_2eproto();

class Bearing;
class Measurements;

// ===================================================================

class Bearing : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Proto.Bearing) */ {
 public:
  Bearing();
  virtual ~Bearing();

  Bearing(const Bearing& from);

  inline Bearing& operator=(const Bearing& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Bearing& default_instance();

  void Swap(Bearing* other);

  // implements Message ----------------------------------------------

  inline Bearing* New() const { return New(NULL); }

  Bearing* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Bearing& from);
  void MergeFrom(const Bearing& from);
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
  void InternalSwap(Bearing* other);
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

  // optional double az = 1;
  void clear_az();
  static const int kAzFieldNumber = 1;
  double az() const;
  void set_az(double value);

  // optional double el = 2;
  void clear_el();
  static const int kElFieldNumber = 2;
  double el() const;
  void set_el(double value);

  // @@protoc_insertion_point(class_scope:Proto.Bearing)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  double az_;
  double el_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_measurement_2eproto();
  friend void protobuf_AssignDesc_measurement_2eproto();
  friend void protobuf_ShutdownFile_measurement_2eproto();

  void InitAsDefaultInstance();
  static Bearing* default_instance_;
};
// -------------------------------------------------------------------

class Measurements : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Proto.Measurements) */ {
 public:
  Measurements();
  virtual ~Measurements();

  Measurements(const Measurements& from);

  inline Measurements& operator=(const Measurements& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Measurements& default_instance();

  void Swap(Measurements* other);

  // implements Message ----------------------------------------------

  inline Measurements* New() const { return New(NULL); }

  Measurements* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Measurements& from);
  void MergeFrom(const Measurements& from);
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
  void InternalSwap(Measurements* other);
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

  // optional uint32 num_feature_points = 1;
  void clear_num_feature_points();
  static const int kNumFeaturePointsFieldNumber = 1;
  ::google::protobuf::uint32 num_feature_points() const;
  void set_num_feature_points(::google::protobuf::uint32 value);

  // repeated .Proto.Position feature_points = 2;
  int feature_points_size() const;
  void clear_feature_points();
  static const int kFeaturePointsFieldNumber = 2;
  const ::Proto::Position& feature_points(int index) const;
  ::Proto::Position* mutable_feature_points(int index);
  ::Proto::Position* add_feature_points();
  ::google::protobuf::RepeatedPtrField< ::Proto::Position >*
      mutable_feature_points();
  const ::google::protobuf::RepeatedPtrField< ::Proto::Position >&
      feature_points() const;

  // repeated .Proto.Bearing measurements = 3;
  int measurements_size() const;
  void clear_measurements();
  static const int kMeasurementsFieldNumber = 3;
  const ::Proto::Bearing& measurements(int index) const;
  ::Proto::Bearing* mutable_measurements(int index);
  ::Proto::Bearing* add_measurements();
  ::google::protobuf::RepeatedPtrField< ::Proto::Bearing >*
      mutable_measurements();
  const ::google::protobuf::RepeatedPtrField< ::Proto::Bearing >&
      measurements() const;

  // @@protoc_insertion_point(class_scope:Proto.Measurements)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::RepeatedPtrField< ::Proto::Position > feature_points_;
  ::google::protobuf::RepeatedPtrField< ::Proto::Bearing > measurements_;
  ::google::protobuf::uint32 num_feature_points_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_measurement_2eproto();
  friend void protobuf_AssignDesc_measurement_2eproto();
  friend void protobuf_ShutdownFile_measurement_2eproto();

  void InitAsDefaultInstance();
  static Measurements* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Bearing

// optional double az = 1;
inline void Bearing::clear_az() {
  az_ = 0;
}
inline double Bearing::az() const {
  // @@protoc_insertion_point(field_get:Proto.Bearing.az)
  return az_;
}
inline void Bearing::set_az(double value) {
  
  az_ = value;
  // @@protoc_insertion_point(field_set:Proto.Bearing.az)
}

// optional double el = 2;
inline void Bearing::clear_el() {
  el_ = 0;
}
inline double Bearing::el() const {
  // @@protoc_insertion_point(field_get:Proto.Bearing.el)
  return el_;
}
inline void Bearing::set_el(double value) {
  
  el_ = value;
  // @@protoc_insertion_point(field_set:Proto.Bearing.el)
}

// -------------------------------------------------------------------

// Measurements

// optional uint32 num_feature_points = 1;
inline void Measurements::clear_num_feature_points() {
  num_feature_points_ = 0u;
}
inline ::google::protobuf::uint32 Measurements::num_feature_points() const {
  // @@protoc_insertion_point(field_get:Proto.Measurements.num_feature_points)
  return num_feature_points_;
}
inline void Measurements::set_num_feature_points(::google::protobuf::uint32 value) {
  
  num_feature_points_ = value;
  // @@protoc_insertion_point(field_set:Proto.Measurements.num_feature_points)
}

// repeated .Proto.Position feature_points = 2;
inline int Measurements::feature_points_size() const {
  return feature_points_.size();
}
inline void Measurements::clear_feature_points() {
  feature_points_.Clear();
}
inline const ::Proto::Position& Measurements::feature_points(int index) const {
  // @@protoc_insertion_point(field_get:Proto.Measurements.feature_points)
  return feature_points_.Get(index);
}
inline ::Proto::Position* Measurements::mutable_feature_points(int index) {
  // @@protoc_insertion_point(field_mutable:Proto.Measurements.feature_points)
  return feature_points_.Mutable(index);
}
inline ::Proto::Position* Measurements::add_feature_points() {
  // @@protoc_insertion_point(field_add:Proto.Measurements.feature_points)
  return feature_points_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Proto::Position >*
Measurements::mutable_feature_points() {
  // @@protoc_insertion_point(field_mutable_list:Proto.Measurements.feature_points)
  return &feature_points_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Proto::Position >&
Measurements::feature_points() const {
  // @@protoc_insertion_point(field_list:Proto.Measurements.feature_points)
  return feature_points_;
}

// repeated .Proto.Bearing measurements = 3;
inline int Measurements::measurements_size() const {
  return measurements_.size();
}
inline void Measurements::clear_measurements() {
  measurements_.Clear();
}
inline const ::Proto::Bearing& Measurements::measurements(int index) const {
  // @@protoc_insertion_point(field_get:Proto.Measurements.measurements)
  return measurements_.Get(index);
}
inline ::Proto::Bearing* Measurements::mutable_measurements(int index) {
  // @@protoc_insertion_point(field_mutable:Proto.Measurements.measurements)
  return measurements_.Mutable(index);
}
inline ::Proto::Bearing* Measurements::add_measurements() {
  // @@protoc_insertion_point(field_add:Proto.Measurements.measurements)
  return measurements_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::Proto::Bearing >*
Measurements::mutable_measurements() {
  // @@protoc_insertion_point(field_mutable_list:Proto.Measurements.measurements)
  return &measurements_;
}
inline const ::google::protobuf::RepeatedPtrField< ::Proto::Bearing >&
Measurements::measurements() const {
  // @@protoc_insertion_point(field_list:Proto.Measurements.measurements)
  return measurements_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Proto

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_measurement_2eproto__INCLUDED
