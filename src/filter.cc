// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/filter.h>
 }

#include "../include/functions/copy.h"
#include "../include/filter.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitFilter::GitFilter(git_filter *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitFilter::~GitFilter() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitFilter::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Filter").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "version", Version);
         Nan::SetPrototypeMethod(tpl, "attributes", Attributes);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Filter").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitFilter::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitFilter cannot be instantiated.");
     }

    GitFilter* object = new GitFilter(static_cast<git_filter *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitFilter::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitFilter::constructor_template), 2, argv).ToLocalChecked());
  }

  git_filter *GitFilter::GetValue() {
    return this->raw;
  }

  git_filter **GitFilter::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitFilter::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitFilter::Version) {
      Local<v8::Value> to;

       unsigned int
         version =
         Nan::ObjectWrap::Unwrap<GitFilter>(info.This())->GetValue()->version;
 // start convert_to_v8 block
     to = Nan::New<Number>( version);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitFilter::Attributes) {
      Local<v8::Value> to;

       const char *
         attributes =
         Nan::ObjectWrap::Unwrap<GitFilter>(info.This())->GetValue()->attributes;
 // start convert_to_v8 block
  if (attributes){
       to = Nan::New<String>(attributes).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitFilter::constructor_template;
 