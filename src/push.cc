// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/push.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/push_options.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitPush::GitPush(git_push *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitPush::~GitPush() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
       }

  void GitPush::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Push").ToLocalChecked());

           Nan::SetMethod(tpl, "initOptions", InitOptions);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Push").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitPush::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitPush cannot be instantiated.");
     }

    GitPush* object = new GitPush(static_cast<git_push *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitPush::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitPush::constructor_template), 2, argv).ToLocalChecked());
  }

  git_push *GitPush::GetValue() {
    return this->raw;
  }

  git_push **GitPush::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitPush::ClearValue() {
    this->raw = NULL;
  }

  
/*
 * @param PushOptions opts
   * @param Number version
     * @return Number  result    */
NAN_METHOD(GitPush::InitOptions) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("PushOptions opts is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number version is required.");
  }

// start convert_from_v8 block
  git_push_options * from_opts;
  from_opts = Nan::ObjectWrap::Unwrap<GitPushOptions>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  unsigned int from_version;
  from_version = (unsigned int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_push_init_options(
from_opts
,from_version
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitPush::constructor_template;
 