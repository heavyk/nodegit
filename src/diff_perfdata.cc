// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
    #include <git2/sys/diff.h>
 }

#include "../include/functions/copy.h"
#include "../include/diff_perfdata.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitDiffPerfdata::GitDiffPerfdata(git_diff_perfdata *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitDiffPerfdata::~GitDiffPerfdata() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDiffPerfdata::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("DiffPerfdata").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "version", Version);
         Nan::SetPrototypeMethod(tpl, "statCalls", StatCalls);
         Nan::SetPrototypeMethod(tpl, "oidCalculations", OidCalculations);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("DiffPerfdata").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitDiffPerfdata::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitDiffPerfdata cannot be instantiated.");
     }

    GitDiffPerfdata* object = new GitDiffPerfdata(static_cast<git_diff_perfdata *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitDiffPerfdata::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitDiffPerfdata::constructor_template), 2, argv).ToLocalChecked());
  }

  git_diff_perfdata *GitDiffPerfdata::GetValue() {
    return this->raw;
  }

  git_diff_perfdata **GitDiffPerfdata::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitDiffPerfdata::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitDiffPerfdata::Version) {
      Local<v8::Value> to;

       unsigned int
         version =
         Nan::ObjectWrap::Unwrap<GitDiffPerfdata>(info.This())->GetValue()->version;
 // start convert_to_v8 block
     to = Nan::New<Number>( version);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffPerfdata::StatCalls) {
      Local<v8::Value> to;

       size_t
         stat_calls =
         Nan::ObjectWrap::Unwrap<GitDiffPerfdata>(info.This())->GetValue()->stat_calls;
 // start convert_to_v8 block
     to = Nan::New<Number>( stat_calls);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffPerfdata::OidCalculations) {
      Local<v8::Value> to;

       size_t
         oid_calculations =
         Nan::ObjectWrap::Unwrap<GitDiffPerfdata>(info.This())->GetValue()->oid_calculations;
 // start convert_to_v8 block
     to = Nan::New<Number>( oid_calculations);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitDiffPerfdata::constructor_template;
 