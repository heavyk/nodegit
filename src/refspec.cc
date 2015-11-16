// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/refspec.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitRefspec::GitRefspec(git_refspec *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitRefspec::~GitRefspec() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                       }

  void GitRefspec::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Refspec").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "direction", Direction);
            Nan::SetPrototypeMethod(tpl, "dst", Dst);
            Nan::SetPrototypeMethod(tpl, "dstMatches", DstMatches);
            Nan::SetPrototypeMethod(tpl, "force", Force);
            Nan::SetPrototypeMethod(tpl, "src", Src);
            Nan::SetPrototypeMethod(tpl, "srcMatches", SrcMatches);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Refspec").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitRefspec::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitRefspec cannot be instantiated.");
     }

    GitRefspec* object = new GitRefspec(static_cast<git_refspec *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitRefspec::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitRefspec::constructor_template), 2, argv).ToLocalChecked());
  }

  git_refspec *GitRefspec::GetValue() {
    return this->raw;
  }

  git_refspec **GitRefspec::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitRefspec::ClearValue() {
    this->raw = NULL;
  }

  
/*
     * @return Number  result    */
NAN_METHOD(GitRefspec::Direction) {
  Nan::EscapableHandleScope scope;

   git_direction result = git_refspec_direction(
Nan::ObjectWrap::Unwrap<GitRefspec>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return String  result    */
NAN_METHOD(GitRefspec::Dst) {
  Nan::EscapableHandleScope scope;

   const char * result = git_refspec_dst(
Nan::ObjectWrap::Unwrap<GitRefspec>(info.This())->GetValue()
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
   
/*
   * @param String refname
     * @return Number  result    */
NAN_METHOD(GitRefspec::DstMatches) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String refname is required.");
  }

// start convert_from_v8 block
  const char * from_refname;

  String::Utf8Value refname(info[0]->ToString());
  from_refname = (const char *) strdup(*refname);
// end convert_from_v8 block
   int result = git_refspec_dst_matches(
Nan::ObjectWrap::Unwrap<GitRefspec>(info.This())->GetValue()
,from_refname
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRefspec::Force) {
  Nan::EscapableHandleScope scope;

   int result = git_refspec_force(
Nan::ObjectWrap::Unwrap<GitRefspec>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return String  result    */
NAN_METHOD(GitRefspec::Src) {
  Nan::EscapableHandleScope scope;

   const char * result = git_refspec_src(
Nan::ObjectWrap::Unwrap<GitRefspec>(info.This())->GetValue()
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
   
/*
   * @param String refname
     * @return Number  result    */
NAN_METHOD(GitRefspec::SrcMatches) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String refname is required.");
  }

// start convert_from_v8 block
  const char * from_refname;

  String::Utf8Value refname(info[0]->ToString());
  from_refname = (const char *) strdup(*refname);
// end convert_from_v8 block
   int result = git_refspec_src_matches(
Nan::ObjectWrap::Unwrap<GitRefspec>(info.This())->GetValue()
,from_refname
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitRefspec::constructor_template;
 