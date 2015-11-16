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
#include "../include/fetch_options.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/remote_callbacks.h"
 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitFetchOptions::GitFetchOptions() {
   git_fetch_options wrappedValue = GIT_FETCH_OPTIONS_INIT;
   this->raw = (git_fetch_options*) malloc(sizeof(git_fetch_options));
  memcpy(this->raw, &wrappedValue, sizeof(git_fetch_options));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitFetchOptions::GitFetchOptions(git_fetch_options* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitFetchOptions::~GitFetchOptions() {
                
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitFetchOptions::ConstructFields() {
             Local<Object> callbacksTemp = GitRemoteCallbacks::New(
            &this->raw->callbacks,
            false
          )->ToObject();
          this->callbacks.Reset(callbacksTemp);

           }

void GitFetchOptions::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("FetchOptions").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("callbacks").ToLocalChecked(), GetCallbacks, SetCallbacks);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("prune").ToLocalChecked(), GetPrune, SetPrune);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("updateFetchhead").ToLocalChecked(), GetUpdateFetchhead, SetUpdateFetchhead);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("downloadTags").ToLocalChecked(), GetDownloadTags, SetDownloadTags);
   
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("FetchOptions").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitFetchOptions::JSNewFunction) {
  GitFetchOptions* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitFetchOptions();
  }
  else {
    instance = new GitFetchOptions(static_cast<git_fetch_options*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitFetchOptions::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitFetchOptions::constructor_template), 2, argv).ToLocalChecked());
}

git_fetch_options *GitFetchOptions::GetValue() {
  return this->raw;
}

git_fetch_options **GitFetchOptions::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitFetchOptions::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitFetchOptions::GetVersion) {

      GitFetchOptions *wrapper = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitFetchOptions::SetVersion) {

      GitFetchOptions *wrapper = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitFetchOptions::GetCallbacks) {

      GitFetchOptions *wrapper = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->callbacks));

     }

    NAN_SETTER(GitFetchOptions::SetCallbacks) {

      GitFetchOptions *wrapper = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info.This());

        Local<Object> callbacks(value->ToObject());

        wrapper->callbacks.Reset(callbacks);

        wrapper->raw->callbacks = *  Nan::ObjectWrap::Unwrap<GitRemoteCallbacks>(callbacks->ToObject())->GetValue() ;

     }

      NAN_GETTER(GitFetchOptions::GetPrune) {

      GitFetchOptions *wrapper = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info.This());

        info.GetReturnValue().Set(Nan::New((int)wrapper->GetValue()->prune));

     }

    NAN_SETTER(GitFetchOptions::SetPrune) {

      GitFetchOptions *wrapper = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info.This());

        if (value->IsNumber()) {
          wrapper->GetValue()->prune = (git_fetch_prune_t) Nan::To<int32_t>(value).FromJust();
        }

     }

      NAN_GETTER(GitFetchOptions::GetUpdateFetchhead) {

      GitFetchOptions *wrapper = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->update_fetchhead));
     }

    NAN_SETTER(GitFetchOptions::SetUpdateFetchhead) {

      GitFetchOptions *wrapper = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->update_fetchhead = (int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitFetchOptions::GetDownloadTags) {

      GitFetchOptions *wrapper = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info.This());

        info.GetReturnValue().Set(Nan::New((int)wrapper->GetValue()->download_tags));

     }

    NAN_SETTER(GitFetchOptions::SetDownloadTags) {

      GitFetchOptions *wrapper = Nan::ObjectWrap::Unwrap<GitFetchOptions>(info.This());

        if (value->IsNumber()) {
          wrapper->GetValue()->download_tags = (git_remote_autotag_option_t) Nan::To<int32_t>(value).FromJust();
        }

     }

   
Nan::Persistent<Function> GitFetchOptions::constructor_template;
