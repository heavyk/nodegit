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
#include "../include/submodule_update_options.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/checkout_options.h"
  #include "../include/fetch_options.h"
 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitSubmoduleUpdateOptions::GitSubmoduleUpdateOptions() {
   git_submodule_update_options wrappedValue = GIT_SUBMODULE_UPDATE_OPTIONS_INIT;
   this->raw = (git_submodule_update_options*) malloc(sizeof(git_submodule_update_options));
  memcpy(this->raw, &wrappedValue, sizeof(git_submodule_update_options));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitSubmoduleUpdateOptions::GitSubmoduleUpdateOptions(git_submodule_update_options* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitSubmoduleUpdateOptions::~GitSubmoduleUpdateOptions() {
               
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitSubmoduleUpdateOptions::ConstructFields() {
             Local<Object> checkout_optsTemp = GitCheckoutOptions::New(
            &this->raw->checkout_opts,
            false
          )->ToObject();
          this->checkout_opts.Reset(checkout_optsTemp);

             Local<Object> fetch_optsTemp = GitFetchOptions::New(
            &this->raw->fetch_opts,
            false
          )->ToObject();
          this->fetch_opts.Reset(fetch_optsTemp);

       }

void GitSubmoduleUpdateOptions::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("SubmoduleUpdateOptions").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("checkoutOpts").ToLocalChecked(), GetCheckoutOpts, SetCheckoutOpts);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("fetchOpts").ToLocalChecked(), GetFetchOpts, SetFetchOpts);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("cloneCheckoutStrategy").ToLocalChecked(), GetCloneCheckoutStrategy, SetCloneCheckoutStrategy);
   
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("SubmoduleUpdateOptions").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitSubmoduleUpdateOptions::JSNewFunction) {
  GitSubmoduleUpdateOptions* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitSubmoduleUpdateOptions();
  }
  else {
    instance = new GitSubmoduleUpdateOptions(static_cast<git_submodule_update_options*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitSubmoduleUpdateOptions::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitSubmoduleUpdateOptions::constructor_template), 2, argv).ToLocalChecked());
}

git_submodule_update_options *GitSubmoduleUpdateOptions::GetValue() {
  return this->raw;
}

git_submodule_update_options **GitSubmoduleUpdateOptions::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitSubmoduleUpdateOptions::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitSubmoduleUpdateOptions::GetVersion) {

      GitSubmoduleUpdateOptions *wrapper = Nan::ObjectWrap::Unwrap<GitSubmoduleUpdateOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitSubmoduleUpdateOptions::SetVersion) {

      GitSubmoduleUpdateOptions *wrapper = Nan::ObjectWrap::Unwrap<GitSubmoduleUpdateOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitSubmoduleUpdateOptions::GetCheckoutOpts) {

      GitSubmoduleUpdateOptions *wrapper = Nan::ObjectWrap::Unwrap<GitSubmoduleUpdateOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->checkout_opts));

     }

    NAN_SETTER(GitSubmoduleUpdateOptions::SetCheckoutOpts) {

      GitSubmoduleUpdateOptions *wrapper = Nan::ObjectWrap::Unwrap<GitSubmoduleUpdateOptions>(info.This());

        Local<Object> checkout_opts(value->ToObject());

        wrapper->checkout_opts.Reset(checkout_opts);

        wrapper->raw->checkout_opts = *  Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(checkout_opts->ToObject())->GetValue() ;

     }

      NAN_GETTER(GitSubmoduleUpdateOptions::GetFetchOpts) {

      GitSubmoduleUpdateOptions *wrapper = Nan::ObjectWrap::Unwrap<GitSubmoduleUpdateOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->fetch_opts));

     }

    NAN_SETTER(GitSubmoduleUpdateOptions::SetFetchOpts) {

      GitSubmoduleUpdateOptions *wrapper = Nan::ObjectWrap::Unwrap<GitSubmoduleUpdateOptions>(info.This());

        Local<Object> fetch_opts(value->ToObject());

        wrapper->fetch_opts.Reset(fetch_opts);

        wrapper->raw->fetch_opts = *  Nan::ObjectWrap::Unwrap<GitFetchOptions>(fetch_opts->ToObject())->GetValue() ;

     }

      NAN_GETTER(GitSubmoduleUpdateOptions::GetCloneCheckoutStrategy) {

      GitSubmoduleUpdateOptions *wrapper = Nan::ObjectWrap::Unwrap<GitSubmoduleUpdateOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->clone_checkout_strategy));
     }

    NAN_SETTER(GitSubmoduleUpdateOptions::SetCloneCheckoutStrategy) {

      GitSubmoduleUpdateOptions *wrapper = Nan::ObjectWrap::Unwrap<GitSubmoduleUpdateOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->clone_checkout_strategy = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

   
Nan::Persistent<Function> GitSubmoduleUpdateOptions::constructor_template;
