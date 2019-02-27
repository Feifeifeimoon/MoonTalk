// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: userInfo.proto

#include "userInfo.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_userInfo_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_userInfo_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_UserInfo;
}  // namespace protobuf_userInfo_2eproto
class UserInfoDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<UserInfo>
      _instance;
} _UserInfo_default_instance_;
class UserListDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<UserList>
      _instance;
} _UserList_default_instance_;
namespace protobuf_userInfo_2eproto {
static void InitDefaultsUserInfo() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_UserInfo_default_instance_;
    new (ptr) ::UserInfo();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::UserInfo::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_UserInfo =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsUserInfo}, {}};

static void InitDefaultsUserList() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_UserList_default_instance_;
    new (ptr) ::UserList();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::UserList::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_UserList =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsUserList}, {
      &protobuf_userInfo_2eproto::scc_info_UserInfo.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_UserInfo.base);
  ::google::protobuf::internal::InitSCC(&scc_info_UserList.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::UserInfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::UserInfo, userid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::UserInfo, imageurl_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::UserInfo, nickname_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::UserInfo, sex_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::UserInfo, sign_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::UserList, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::UserList, userinfo_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::UserInfo)},
  { 10, -1, sizeof(::UserList)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::_UserInfo_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::_UserList_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "userInfo.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\016userInfo.proto\"Y\n\010UserInfo\022\016\n\006UserID\030\001"
      " \001(\t\022\020\n\010ImageUrl\030\002 \001(\t\022\020\n\010NickName\030\003 \001(\t"
      "\022\013\n\003Sex\030\004 \001(\005\022\014\n\004Sign\030\005 \001(\t\"\'\n\010UserList\022"
      "\033\n\010userInfo\030\001 \003(\0132\t.UserInfob\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 156);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "userInfo.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_userInfo_2eproto

// ===================================================================

void UserInfo::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int UserInfo::kUserIDFieldNumber;
const int UserInfo::kImageUrlFieldNumber;
const int UserInfo::kNickNameFieldNumber;
const int UserInfo::kSexFieldNumber;
const int UserInfo::kSignFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

UserInfo::UserInfo()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_userInfo_2eproto::scc_info_UserInfo.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:UserInfo)
}
UserInfo::UserInfo(const UserInfo& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  userid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.userid().size() > 0) {
    userid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.userid_);
  }
  imageurl_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.imageurl().size() > 0) {
    imageurl_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.imageurl_);
  }
  nickname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.nickname().size() > 0) {
    nickname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.nickname_);
  }
  sign_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.sign().size() > 0) {
    sign_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.sign_);
  }
  sex_ = from.sex_;
  // @@protoc_insertion_point(copy_constructor:UserInfo)
}

void UserInfo::SharedCtor() {
  userid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  imageurl_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  nickname_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sign_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sex_ = 0;
}

UserInfo::~UserInfo() {
  // @@protoc_insertion_point(destructor:UserInfo)
  SharedDtor();
}

void UserInfo::SharedDtor() {
  userid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  imageurl_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  nickname_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sign_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void UserInfo::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* UserInfo::descriptor() {
  ::protobuf_userInfo_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_userInfo_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const UserInfo& UserInfo::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_userInfo_2eproto::scc_info_UserInfo.base);
  return *internal_default_instance();
}


void UserInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:UserInfo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  userid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  imageurl_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  nickname_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sign_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  sex_ = 0;
  _internal_metadata_.Clear();
}

bool UserInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:UserInfo)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string UserID = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_userid()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->userid().data(), static_cast<int>(this->userid().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "UserInfo.UserID"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string ImageUrl = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_imageurl()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->imageurl().data(), static_cast<int>(this->imageurl().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "UserInfo.ImageUrl"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string NickName = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_nickname()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->nickname().data(), static_cast<int>(this->nickname().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "UserInfo.NickName"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int32 Sex = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &sex_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string Sign = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_sign()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->sign().data(), static_cast<int>(this->sign().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "UserInfo.Sign"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:UserInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:UserInfo)
  return false;
#undef DO_
}

void UserInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:UserInfo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string UserID = 1;
  if (this->userid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->userid().data(), static_cast<int>(this->userid().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "UserInfo.UserID");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->userid(), output);
  }

  // string ImageUrl = 2;
  if (this->imageurl().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->imageurl().data(), static_cast<int>(this->imageurl().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "UserInfo.ImageUrl");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->imageurl(), output);
  }

  // string NickName = 3;
  if (this->nickname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->nickname().data(), static_cast<int>(this->nickname().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "UserInfo.NickName");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->nickname(), output);
  }

  // int32 Sex = 4;
  if (this->sex() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->sex(), output);
  }

  // string Sign = 5;
  if (this->sign().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->sign().data(), static_cast<int>(this->sign().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "UserInfo.Sign");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->sign(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:UserInfo)
}

::google::protobuf::uint8* UserInfo::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:UserInfo)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string UserID = 1;
  if (this->userid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->userid().data(), static_cast<int>(this->userid().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "UserInfo.UserID");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->userid(), target);
  }

  // string ImageUrl = 2;
  if (this->imageurl().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->imageurl().data(), static_cast<int>(this->imageurl().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "UserInfo.ImageUrl");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->imageurl(), target);
  }

  // string NickName = 3;
  if (this->nickname().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->nickname().data(), static_cast<int>(this->nickname().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "UserInfo.NickName");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->nickname(), target);
  }

  // int32 Sex = 4;
  if (this->sex() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->sex(), target);
  }

  // string Sign = 5;
  if (this->sign().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->sign().data(), static_cast<int>(this->sign().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "UserInfo.Sign");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->sign(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:UserInfo)
  return target;
}

size_t UserInfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:UserInfo)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string UserID = 1;
  if (this->userid().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->userid());
  }

  // string ImageUrl = 2;
  if (this->imageurl().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->imageurl());
  }

  // string NickName = 3;
  if (this->nickname().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->nickname());
  }

  // string Sign = 5;
  if (this->sign().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->sign());
  }

  // int32 Sex = 4;
  if (this->sex() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->sex());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void UserInfo::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:UserInfo)
  GOOGLE_DCHECK_NE(&from, this);
  const UserInfo* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const UserInfo>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:UserInfo)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:UserInfo)
    MergeFrom(*source);
  }
}

void UserInfo::MergeFrom(const UserInfo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:UserInfo)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.userid().size() > 0) {

    userid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.userid_);
  }
  if (from.imageurl().size() > 0) {

    imageurl_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.imageurl_);
  }
  if (from.nickname().size() > 0) {

    nickname_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.nickname_);
  }
  if (from.sign().size() > 0) {

    sign_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.sign_);
  }
  if (from.sex() != 0) {
    set_sex(from.sex());
  }
}

void UserInfo::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:UserInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UserInfo::CopyFrom(const UserInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:UserInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UserInfo::IsInitialized() const {
  return true;
}

void UserInfo::Swap(UserInfo* other) {
  if (other == this) return;
  InternalSwap(other);
}
void UserInfo::InternalSwap(UserInfo* other) {
  using std::swap;
  userid_.Swap(&other->userid_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  imageurl_.Swap(&other->imageurl_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  nickname_.Swap(&other->nickname_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  sign_.Swap(&other->sign_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(sex_, other->sex_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata UserInfo::GetMetadata() const {
  protobuf_userInfo_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_userInfo_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void UserList::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int UserList::kUserInfoFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

UserList::UserList()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_userInfo_2eproto::scc_info_UserList.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:UserList)
}
UserList::UserList(const UserList& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      userinfo_(from.userinfo_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:UserList)
}

void UserList::SharedCtor() {
}

UserList::~UserList() {
  // @@protoc_insertion_point(destructor:UserList)
  SharedDtor();
}

void UserList::SharedDtor() {
}

void UserList::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* UserList::descriptor() {
  ::protobuf_userInfo_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_userInfo_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const UserList& UserList::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_userInfo_2eproto::scc_info_UserList.base);
  return *internal_default_instance();
}


void UserList::Clear() {
// @@protoc_insertion_point(message_clear_start:UserList)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  userinfo_.Clear();
  _internal_metadata_.Clear();
}

bool UserList::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:UserList)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .UserInfo userInfo = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_userinfo()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:UserList)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:UserList)
  return false;
#undef DO_
}

void UserList::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:UserList)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .UserInfo userInfo = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->userinfo_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1,
      this->userinfo(static_cast<int>(i)),
      output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:UserList)
}

::google::protobuf::uint8* UserList::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:UserList)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .UserInfo userInfo = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->userinfo_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->userinfo(static_cast<int>(i)), deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:UserList)
  return target;
}

size_t UserList::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:UserList)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .UserInfo userInfo = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->userinfo_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->userinfo(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void UserList::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:UserList)
  GOOGLE_DCHECK_NE(&from, this);
  const UserList* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const UserList>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:UserList)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:UserList)
    MergeFrom(*source);
  }
}

void UserList::MergeFrom(const UserList& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:UserList)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  userinfo_.MergeFrom(from.userinfo_);
}

void UserList::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:UserList)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void UserList::CopyFrom(const UserList& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:UserList)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UserList::IsInitialized() const {
  return true;
}

void UserList::Swap(UserList* other) {
  if (other == this) return;
  InternalSwap(other);
}
void UserList::InternalSwap(UserList* other) {
  using std::swap;
  CastToBase(&userinfo_)->InternalSwap(CastToBase(&other->userinfo_));
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata UserList::GetMetadata() const {
  protobuf_userInfo_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_userInfo_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::UserInfo* Arena::CreateMaybeMessage< ::UserInfo >(Arena* arena) {
  return Arena::CreateInternal< ::UserInfo >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::UserList* Arena::CreateMaybeMessage< ::UserList >(Arena* arena) {
  return Arena::CreateInternal< ::UserList >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
