// This is a generated file, modify: generate/templates/struct_content.cc.
#include <nan.h>
#include <string.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32

extern "C" {
  #include <git2.h>
 }

#include <iostream>
#include "../include/functions/copy.h"
#include "../include/push_options.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/remote_callbacks.h"
 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitPushOptions::GitPushOptions() {
   git_push_options wrappedValue = GIT_PUSH_OPTIONS_INIT;
   this->raw = (git_push_options*) malloc(sizeof(git_push_options));
  memcpy(this->raw, &wrappedValue, sizeof(git_push_options));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitPushOptions::GitPushOptions(git_push_options* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitPushOptions::~GitPushOptions() {
            
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitPushOptions::ConstructFields() {
                Local<Object> callbacksTemp = GitRemoteCallbacks::New(
            &this->raw->callbacks,
            false
          )->ToObject();
          this->callbacks.Reset(callbacksTemp);

    }

void GitPushOptions::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("PushOptions").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("pbParallelism").ToLocalChecked(), GetPbParallelism, SetPbParallelism);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("callbacks").ToLocalChecked(), GetCallbacks, SetCallbacks);
   
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("PushOptions").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitPushOptions::JSNewFunction) {
  GitPushOptions* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitPushOptions();
  }
  else {
    instance = new GitPushOptions(static_cast<git_push_options*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitPushOptions::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitPushOptions::constructor_template), 2, argv).ToLocalChecked());
}

git_push_options *GitPushOptions::GetValue() {
  return this->raw;
}

git_push_options **GitPushOptions::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitPushOptions::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitPushOptions::GetVersion) {

      GitPushOptions *wrapper = Nan::ObjectWrap::Unwrap<GitPushOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitPushOptions::SetVersion) {

      GitPushOptions *wrapper = Nan::ObjectWrap::Unwrap<GitPushOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitPushOptions::GetPbParallelism) {

      GitPushOptions *wrapper = Nan::ObjectWrap::Unwrap<GitPushOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->pb_parallelism));
     }

    NAN_SETTER(GitPushOptions::SetPbParallelism) {

      GitPushOptions *wrapper = Nan::ObjectWrap::Unwrap<GitPushOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->pb_parallelism = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitPushOptions::GetCallbacks) {

      GitPushOptions *wrapper = Nan::ObjectWrap::Unwrap<GitPushOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->callbacks));

     }

    NAN_SETTER(GitPushOptions::SetCallbacks) {

      GitPushOptions *wrapper = Nan::ObjectWrap::Unwrap<GitPushOptions>(info.This());

        Local<Object> callbacks(value->ToObject());

        wrapper->callbacks.Reset(callbacks);

        wrapper->raw->callbacks = *  Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(callbacks->ToObject())->GetValue() ;

     }

   
Nan::Persistent<Function> GitPushOptions::constructor_template;
