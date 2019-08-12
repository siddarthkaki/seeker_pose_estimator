// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: measurement.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "measurement.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Proto {

namespace {

const ::google::protobuf::Descriptor* Bearing_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Bearing_reflection_ = NULL;
const ::google::protobuf::Descriptor* Measurements_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Measurements_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_measurement_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_measurement_2eproto() {
  protobuf_AddDesc_measurement_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "measurement.proto");
  GOOGLE_CHECK(file != NULL);
  Bearing_descriptor_ = file->message_type(0);
  static const int Bearing_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Bearing, az_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Bearing, el_),
  };
  Bearing_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Bearing_descriptor_,
      Bearing::default_instance_,
      Bearing_offsets_,
      -1,
      -1,
      -1,
      sizeof(Bearing),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Bearing, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Bearing, _is_default_instance_));
  Measurements_descriptor_ = file->message_type(1);
  static const int Measurements_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Measurements, num_feature_points_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Measurements, feature_points_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Measurements, measurements_),
  };
  Measurements_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Measurements_descriptor_,
      Measurements::default_instance_,
      Measurements_offsets_,
      -1,
      -1,
      -1,
      sizeof(Measurements),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Measurements, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Measurements, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_measurement_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Bearing_descriptor_, &Bearing::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Measurements_descriptor_, &Measurements::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_measurement_2eproto() {
  delete Bearing::default_instance_;
  delete Bearing_reflection_;
  delete Measurements::default_instance_;
  delete Measurements_reflection_;
}

void protobuf_AddDesc_measurement_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_measurement_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::Proto::protobuf_AddDesc_pose_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\021measurement.proto\022\005Proto\032\npose.proto\"!"
    "\n\007Bearing\022\n\n\002az\030\001 \001(\001\022\n\n\002el\030\002 \001(\001\"y\n\014Mea"
    "surements\022\032\n\022num_feature_points\030\001 \001(\r\022\'\n"
    "\016feature_points\030\002 \003(\0132\017.Proto.Position\022$"
    "\n\014measurements\030\003 \003(\0132\016.Proto.Bearingb\006pr"
    "oto3", 204);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "measurement.proto", &protobuf_RegisterTypes);
  Bearing::default_instance_ = new Bearing();
  Measurements::default_instance_ = new Measurements();
  Bearing::default_instance_->InitAsDefaultInstance();
  Measurements::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_measurement_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_measurement_2eproto {
  StaticDescriptorInitializer_measurement_2eproto() {
    protobuf_AddDesc_measurement_2eproto();
  }
} static_descriptor_initializer_measurement_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Bearing::kAzFieldNumber;
const int Bearing::kElFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Bearing::Bearing()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Proto.Bearing)
}

void Bearing::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

Bearing::Bearing(const Bearing& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Proto.Bearing)
}

void Bearing::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  az_ = 0;
  el_ = 0;
}

Bearing::~Bearing() {
  // @@protoc_insertion_point(destructor:Proto.Bearing)
  SharedDtor();
}

void Bearing::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Bearing::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Bearing::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Bearing_descriptor_;
}

const Bearing& Bearing::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_measurement_2eproto();
  return *default_instance_;
}

Bearing* Bearing::default_instance_ = NULL;

Bearing* Bearing::New(::google::protobuf::Arena* arena) const {
  Bearing* n = new Bearing;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Bearing::Clear() {
// @@protoc_insertion_point(message_clear_start:Proto.Bearing)
#if defined(__clang__)
#define ZR_HELPER_(f) \
  _Pragma("clang diagnostic push") \
  _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") \
  __builtin_offsetof(Bearing, f) \
  _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<Bearing*>(16)->f)
#endif

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(az_, el_);

#undef ZR_HELPER_
#undef ZR_

}

bool Bearing::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Proto.Bearing)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional double az = 1;
      case 1: {
        if (tag == 9) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &az_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(17)) goto parse_el;
        break;
      }

      // optional double el = 2;
      case 2: {
        if (tag == 17) {
         parse_el:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &el_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Proto.Bearing)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Proto.Bearing)
  return false;
#undef DO_
}

void Bearing::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Proto.Bearing)
  // optional double az = 1;
  if (this->az() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->az(), output);
  }

  // optional double el = 2;
  if (this->el() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->el(), output);
  }

  // @@protoc_insertion_point(serialize_end:Proto.Bearing)
}

::google::protobuf::uint8* Bearing::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Proto.Bearing)
  // optional double az = 1;
  if (this->az() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->az(), target);
  }

  // optional double el = 2;
  if (this->el() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->el(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:Proto.Bearing)
  return target;
}

int Bearing::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:Proto.Bearing)
  int total_size = 0;

  // optional double az = 1;
  if (this->az() != 0) {
    total_size += 1 + 8;
  }

  // optional double el = 2;
  if (this->el() != 0) {
    total_size += 1 + 8;
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Bearing::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Proto.Bearing)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const Bearing* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Bearing>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Proto.Bearing)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Proto.Bearing)
    MergeFrom(*source);
  }
}

void Bearing::MergeFrom(const Bearing& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Proto.Bearing)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.az() != 0) {
    set_az(from.az());
  }
  if (from.el() != 0) {
    set_el(from.el());
  }
}

void Bearing::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Proto.Bearing)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Bearing::CopyFrom(const Bearing& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Proto.Bearing)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Bearing::IsInitialized() const {

  return true;
}

void Bearing::Swap(Bearing* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Bearing::InternalSwap(Bearing* other) {
  std::swap(az_, other->az_);
  std::swap(el_, other->el_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Bearing::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Bearing_descriptor_;
  metadata.reflection = Bearing_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Bearing

// optional double az = 1;
void Bearing::clear_az() {
  az_ = 0;
}
 double Bearing::az() const {
  // @@protoc_insertion_point(field_get:Proto.Bearing.az)
  return az_;
}
 void Bearing::set_az(double value) {
  
  az_ = value;
  // @@protoc_insertion_point(field_set:Proto.Bearing.az)
}

// optional double el = 2;
void Bearing::clear_el() {
  el_ = 0;
}
 double Bearing::el() const {
  // @@protoc_insertion_point(field_get:Proto.Bearing.el)
  return el_;
}
 void Bearing::set_el(double value) {
  
  el_ = value;
  // @@protoc_insertion_point(field_set:Proto.Bearing.el)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Measurements::kNumFeaturePointsFieldNumber;
const int Measurements::kFeaturePointsFieldNumber;
const int Measurements::kMeasurementsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Measurements::Measurements()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Proto.Measurements)
}

void Measurements::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

Measurements::Measurements(const Measurements& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:Proto.Measurements)
}

void Measurements::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  num_feature_points_ = 0u;
}

Measurements::~Measurements() {
  // @@protoc_insertion_point(destructor:Proto.Measurements)
  SharedDtor();
}

void Measurements::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Measurements::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Measurements::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Measurements_descriptor_;
}

const Measurements& Measurements::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_measurement_2eproto();
  return *default_instance_;
}

Measurements* Measurements::default_instance_ = NULL;

Measurements* Measurements::New(::google::protobuf::Arena* arena) const {
  Measurements* n = new Measurements;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Measurements::Clear() {
// @@protoc_insertion_point(message_clear_start:Proto.Measurements)
  num_feature_points_ = 0u;
  feature_points_.Clear();
  measurements_.Clear();
}

bool Measurements::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Proto.Measurements)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 num_feature_points = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &num_feature_points_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_feature_points;
        break;
      }

      // repeated .Proto.Position feature_points = 2;
      case 2: {
        if (tag == 18) {
         parse_feature_points:
          DO_(input->IncrementRecursionDepth());
         parse_loop_feature_points:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_feature_points()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_loop_feature_points;
        if (input->ExpectTag(26)) goto parse_loop_measurements;
        input->UnsafeDecrementRecursionDepth();
        break;
      }

      // repeated .Proto.Bearing measurements = 3;
      case 3: {
        if (tag == 26) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_measurements:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_measurements()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_loop_measurements;
        input->UnsafeDecrementRecursionDepth();
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:Proto.Measurements)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Proto.Measurements)
  return false;
#undef DO_
}

void Measurements::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Proto.Measurements)
  // optional uint32 num_feature_points = 1;
  if (this->num_feature_points() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->num_feature_points(), output);
  }

  // repeated .Proto.Position feature_points = 2;
  for (unsigned int i = 0, n = this->feature_points_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->feature_points(i), output);
  }

  // repeated .Proto.Bearing measurements = 3;
  for (unsigned int i = 0, n = this->measurements_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->measurements(i), output);
  }

  // @@protoc_insertion_point(serialize_end:Proto.Measurements)
}

::google::protobuf::uint8* Measurements::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:Proto.Measurements)
  // optional uint32 num_feature_points = 1;
  if (this->num_feature_points() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->num_feature_points(), target);
  }

  // repeated .Proto.Position feature_points = 2;
  for (unsigned int i = 0, n = this->feature_points_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        2, this->feature_points(i), false, target);
  }

  // repeated .Proto.Bearing measurements = 3;
  for (unsigned int i = 0, n = this->measurements_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        3, this->measurements(i), false, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:Proto.Measurements)
  return target;
}

int Measurements::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:Proto.Measurements)
  int total_size = 0;

  // optional uint32 num_feature_points = 1;
  if (this->num_feature_points() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->num_feature_points());
  }

  // repeated .Proto.Position feature_points = 2;
  total_size += 1 * this->feature_points_size();
  for (int i = 0; i < this->feature_points_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->feature_points(i));
  }

  // repeated .Proto.Bearing measurements = 3;
  total_size += 1 * this->measurements_size();
  for (int i = 0; i < this->measurements_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->measurements(i));
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Measurements::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Proto.Measurements)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const Measurements* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Measurements>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Proto.Measurements)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Proto.Measurements)
    MergeFrom(*source);
  }
}

void Measurements::MergeFrom(const Measurements& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Proto.Measurements)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  feature_points_.MergeFrom(from.feature_points_);
  measurements_.MergeFrom(from.measurements_);
  if (from.num_feature_points() != 0) {
    set_num_feature_points(from.num_feature_points());
  }
}

void Measurements::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Proto.Measurements)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Measurements::CopyFrom(const Measurements& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Proto.Measurements)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Measurements::IsInitialized() const {

  return true;
}

void Measurements::Swap(Measurements* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Measurements::InternalSwap(Measurements* other) {
  std::swap(num_feature_points_, other->num_feature_points_);
  feature_points_.UnsafeArenaSwap(&other->feature_points_);
  measurements_.UnsafeArenaSwap(&other->measurements_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Measurements::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Measurements_descriptor_;
  metadata.reflection = Measurements_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Measurements

// optional uint32 num_feature_points = 1;
void Measurements::clear_num_feature_points() {
  num_feature_points_ = 0u;
}
 ::google::protobuf::uint32 Measurements::num_feature_points() const {
  // @@protoc_insertion_point(field_get:Proto.Measurements.num_feature_points)
  return num_feature_points_;
}
 void Measurements::set_num_feature_points(::google::protobuf::uint32 value) {
  
  num_feature_points_ = value;
  // @@protoc_insertion_point(field_set:Proto.Measurements.num_feature_points)
}

// repeated .Proto.Position feature_points = 2;
int Measurements::feature_points_size() const {
  return feature_points_.size();
}
void Measurements::clear_feature_points() {
  feature_points_.Clear();
}
const ::Proto::Position& Measurements::feature_points(int index) const {
  // @@protoc_insertion_point(field_get:Proto.Measurements.feature_points)
  return feature_points_.Get(index);
}
::Proto::Position* Measurements::mutable_feature_points(int index) {
  // @@protoc_insertion_point(field_mutable:Proto.Measurements.feature_points)
  return feature_points_.Mutable(index);
}
::Proto::Position* Measurements::add_feature_points() {
  // @@protoc_insertion_point(field_add:Proto.Measurements.feature_points)
  return feature_points_.Add();
}
::google::protobuf::RepeatedPtrField< ::Proto::Position >*
Measurements::mutable_feature_points() {
  // @@protoc_insertion_point(field_mutable_list:Proto.Measurements.feature_points)
  return &feature_points_;
}
const ::google::protobuf::RepeatedPtrField< ::Proto::Position >&
Measurements::feature_points() const {
  // @@protoc_insertion_point(field_list:Proto.Measurements.feature_points)
  return feature_points_;
}

// repeated .Proto.Bearing measurements = 3;
int Measurements::measurements_size() const {
  return measurements_.size();
}
void Measurements::clear_measurements() {
  measurements_.Clear();
}
const ::Proto::Bearing& Measurements::measurements(int index) const {
  // @@protoc_insertion_point(field_get:Proto.Measurements.measurements)
  return measurements_.Get(index);
}
::Proto::Bearing* Measurements::mutable_measurements(int index) {
  // @@protoc_insertion_point(field_mutable:Proto.Measurements.measurements)
  return measurements_.Mutable(index);
}
::Proto::Bearing* Measurements::add_measurements() {
  // @@protoc_insertion_point(field_add:Proto.Measurements.measurements)
  return measurements_.Add();
}
::google::protobuf::RepeatedPtrField< ::Proto::Bearing >*
Measurements::mutable_measurements() {
  // @@protoc_insertion_point(field_mutable_list:Proto.Measurements.measurements)
  return &measurements_;
}
const ::google::protobuf::RepeatedPtrField< ::Proto::Bearing >&
Measurements::measurements() const {
  // @@protoc_insertion_point(field_list:Proto.Measurements.measurements)
  return measurements_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace Proto

// @@protoc_insertion_point(global_scope)
