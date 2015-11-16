// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/index_time.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitIndexTime::GitIndexTime(git_index_time *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitIndexTime::~GitIndexTime() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitIndexTime::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("IndexTime").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "seconds", Seconds);
         Nan::SetPrototypeMethod(tpl, "nanoseconds", Nanoseconds);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("IndexTime").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitIndexTime::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitIndexTime cannot be instantiated.");
     }

    GitIndexTime* object = new GitIndexTime(static_cast<git_index_time *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitIndexTime::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitIndexTime::constructor_template), 2, argv).ToLocalChecked());
  }

  git_index_time *GitIndexTime::GetValue() {
    return this->raw;
  }

  git_index_time **GitIndexTime::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitIndexTime::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitIndexTime::Seconds) {
      Local<v8::Value> to;

       int32_t
         seconds =
         Nan::ObjectWrap::Unwrap<GitIndexTime>(info.This())->GetValue()->seconds;
 // start convert_to_v8 block
     to = Nan::New<Number>( seconds);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitIndexTime::Nanoseconds) {
      Local<v8::Value> to;

       uint32_t
         nanoseconds =
         Nan::ObjectWrap::Unwrap<GitIndexTime>(info.This())->GetValue()->nanoseconds;
 // start convert_to_v8 block
     to = Nan::New<Number>( nanoseconds);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitIndexTime::constructor_template;
 