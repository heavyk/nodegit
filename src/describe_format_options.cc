// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/describe_format_options.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitDescribeFormatOptions::GitDescribeFormatOptions(git_describe_format_options *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitDescribeFormatOptions::~GitDescribeFormatOptions() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDescribeFormatOptions::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("DescribeFormatOptions").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "version", Version);
         Nan::SetPrototypeMethod(tpl, "abbreviatedSize", AbbreviatedSize);
         Nan::SetPrototypeMethod(tpl, "alwaysUseLongFormat", AlwaysUseLongFormat);
         Nan::SetPrototypeMethod(tpl, "dirtySuffix", DirtySuffix);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("DescribeFormatOptions").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitDescribeFormatOptions::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitDescribeFormatOptions cannot be instantiated.");
     }

    GitDescribeFormatOptions* object = new GitDescribeFormatOptions(static_cast<git_describe_format_options *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitDescribeFormatOptions::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitDescribeFormatOptions::constructor_template), 2, argv).ToLocalChecked());
  }

  git_describe_format_options *GitDescribeFormatOptions::GetValue() {
    return this->raw;
  }

  git_describe_format_options **GitDescribeFormatOptions::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitDescribeFormatOptions::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitDescribeFormatOptions::Version) {
      Local<v8::Value> to;

       unsigned int
         version =
         Nan::ObjectWrap::Unwrap<GitDescribeFormatOptions>(info.This())->GetValue()->version;
 // start convert_to_v8 block
     to = Nan::New<Number>( version);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDescribeFormatOptions::AbbreviatedSize) {
      Local<v8::Value> to;

       unsigned int
         abbreviated_size =
         Nan::ObjectWrap::Unwrap<GitDescribeFormatOptions>(info.This())->GetValue()->abbreviated_size;
 // start convert_to_v8 block
     to = Nan::New<Number>( abbreviated_size);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDescribeFormatOptions::AlwaysUseLongFormat) {
      Local<v8::Value> to;

       int
         always_use_long_format =
         Nan::ObjectWrap::Unwrap<GitDescribeFormatOptions>(info.This())->GetValue()->always_use_long_format;
 // start convert_to_v8 block
     to = Nan::New<Number>( always_use_long_format);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDescribeFormatOptions::DirtySuffix) {
      Local<v8::Value> to;

       const char *
         dirty_suffix =
         Nan::ObjectWrap::Unwrap<GitDescribeFormatOptions>(info.This())->GetValue()->dirty_suffix;
 // start convert_to_v8 block
  if (dirty_suffix){
       to = Nan::New<String>(dirty_suffix).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitDescribeFormatOptions::constructor_template;
 