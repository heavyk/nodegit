// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/oid.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitOid::GitOid(git_oid *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitOid::~GitOid() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                      }

  void GitOid::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Oid").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "cmp", Cmp);
            Nan::SetPrototypeMethod(tpl, "cpy", Cpy);
            Nan::SetPrototypeMethod(tpl, "equal", Equal);
             Nan::SetMethod(tpl, "fromString", Fromstr);
            Nan::SetPrototypeMethod(tpl, "iszero", Iszero);
            Nan::SetPrototypeMethod(tpl, "ncmp", Ncmp);
            Nan::SetPrototypeMethod(tpl, "strcmp", Strcmp);
            Nan::SetPrototypeMethod(tpl, "streq", Streq);
            Nan::SetPrototypeMethod(tpl, "tostrS", TostrS);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Oid").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitOid::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitOid cannot be instantiated.");
     }

    GitOid* object = new GitOid(static_cast<git_oid *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitOid::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitOid::constructor_template), 2, argv).ToLocalChecked());
  }

  git_oid *GitOid::GetValue() {
    return this->raw;
  }

  git_oid **GitOid::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitOid::ClearValue() {
    this->raw = NULL;
  }

  
/*
       * @return Number  result    */
NAN_METHOD(GitOid::Cmp) {
  Nan::EscapableHandleScope scope;

   int result = git_oid_cmp(
Nan::ObjectWrap::Unwrap<GitOid>(info.This())->GetValue()
,Nan::ObjectWrap::Unwrap<GitOid>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
      * @return Oid out    */
NAN_METHOD(GitOid::Cpy) {
  Nan::EscapableHandleScope scope;

  git_oid *out = (git_oid *)malloc(sizeof(git_oid));
 git_oid_cpy(
out
,Nan::ObjectWrap::Unwrap<GitOid>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitOid out
       to = GitOid::New((void *)out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
       * @return Number  result    */
NAN_METHOD(GitOid::Equal) {
  Nan::EscapableHandleScope scope;

   int result = git_oid_equal(
Nan::ObjectWrap::Unwrap<GitOid>(info.This())->GetValue()
,Nan::ObjectWrap::Unwrap<GitOid>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
  * @param String str
     * @return Oid out    */
NAN_METHOD(GitOid::Fromstr) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String str is required.");
  }

  git_oid *out = (git_oid *)malloc(sizeof(git_oid));
// start convert_from_v8 block
  const char * from_str;

  String::Utf8Value str(info[0]->ToString());
  from_str = (const char *) strdup(*str);
// end convert_from_v8 block
 git_oid_fromstr(
out
,from_str
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitOid out
       to = GitOid::New((void *)out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitOid::Iszero) {
  Nan::EscapableHandleScope scope;

   int result = git_oid_iszero(
Nan::ObjectWrap::Unwrap<GitOid>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @param Number len
     * @return Number  result    */
NAN_METHOD(GitOid::Ncmp) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number len is required.");
  }

// start convert_from_v8 block
  size_t from_len;
  from_len = (size_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_oid_ncmp(
Nan::ObjectWrap::Unwrap<GitOid>(info.This())->GetValue()
,Nan::ObjectWrap::Unwrap<GitOid>(info.This())->GetValue()
,from_len
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String str
     * @return Number  result    */
NAN_METHOD(GitOid::Strcmp) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String str is required.");
  }

// start convert_from_v8 block
  const char * from_str;

  String::Utf8Value str(info[0]->ToString());
  from_str = (const char *) strdup(*str);
// end convert_from_v8 block
   int result = git_oid_strcmp(
Nan::ObjectWrap::Unwrap<GitOid>(info.This())->GetValue()
,from_str
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String str
     * @return Number  result    */
NAN_METHOD(GitOid::Streq) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String str is required.");
  }

// start convert_from_v8 block
  const char * from_str;

  String::Utf8Value str(info[0]->ToString());
  from_str = (const char *) strdup(*str);
// end convert_from_v8 block
   int result = git_oid_streq(
Nan::ObjectWrap::Unwrap<GitOid>(info.This())->GetValue()
,from_str
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return String  result    */
NAN_METHOD(GitOid::TostrS) {
  Nan::EscapableHandleScope scope;

   char * result = git_oid_tostr_s(
Nan::ObjectWrap::Unwrap<GitOid>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  if (result){
       to = Nan::New<String>(result).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitOid::constructor_template;
 