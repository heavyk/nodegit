// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/time.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitTime::GitTime(git_time *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitTime::~GitTime() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitTime::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Time").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "time", Time);
         Nan::SetPrototypeMethod(tpl, "offset", Offset);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Time").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitTime::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitTime cannot be instantiated.");
     }

    GitTime* object = new GitTime(static_cast<git_time *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitTime::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitTime::constructor_template), 2, argv).ToLocalChecked());
  }

  git_time *GitTime::GetValue() {
    return this->raw;
  }

  git_time **GitTime::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitTime::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitTime::Time) {
      Local<v8::Value> to;

       git_time_t
         time =
         Nan::ObjectWrap::Unwrap<GitTime>(info.This())->GetValue()->time;
 // start convert_to_v8 block
     to = Nan::New<Number>( time);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitTime::Offset) {
      Local<v8::Value> to;

       int
         offset =
         Nan::ObjectWrap::Unwrap<GitTime>(info.This())->GetValue()->offset;
 // start convert_to_v8 block
     to = Nan::New<Number>( offset);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitTime::constructor_template;
 