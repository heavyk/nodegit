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
#include "../include/revert_options.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/merge_options.h"
  #include "../include/checkout_options.h"
 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitRevertOptions::GitRevertOptions() {
   git_revert_options wrappedValue = GIT_REVERT_OPTIONS_INIT;
   this->raw = (git_revert_options*) malloc(sizeof(git_revert_options));
  memcpy(this->raw, &wrappedValue, sizeof(git_revert_options));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitRevertOptions::GitRevertOptions(git_revert_options* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitRevertOptions::~GitRevertOptions() {
               
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitRevertOptions::ConstructFields() {
                Local<Object> merge_optsTemp = GitMergeOptions::New(
            &this->raw->merge_opts,
            false
          )->ToObject();
          this->merge_opts.Reset(merge_optsTemp);

             Local<Object> checkout_optsTemp = GitCheckoutOptions::New(
            &this->raw->checkout_opts,
            false
          )->ToObject();
          this->checkout_opts.Reset(checkout_optsTemp);

    }

void GitRevertOptions::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("RevertOptions").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("mainline").ToLocalChecked(), GetMainline, SetMainline);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("mergeOpts").ToLocalChecked(), GetMergeOpts, SetMergeOpts);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("checkoutOpts").ToLocalChecked(), GetCheckoutOpts, SetCheckoutOpts);
   
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("RevertOptions").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitRevertOptions::JSNewFunction) {
  GitRevertOptions* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitRevertOptions();
  }
  else {
    instance = new GitRevertOptions(static_cast<git_revert_options*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitRevertOptions::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitRevertOptions::constructor_template), 2, argv).ToLocalChecked());
}

git_revert_options *GitRevertOptions::GetValue() {
  return this->raw;
}

git_revert_options **GitRevertOptions::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitRevertOptions::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitRevertOptions::GetVersion) {

      GitRevertOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRevertOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitRevertOptions::SetVersion) {

      GitRevertOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRevertOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitRevertOptions::GetMainline) {

      GitRevertOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRevertOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->mainline));
     }

    NAN_SETTER(GitRevertOptions::SetMainline) {

      GitRevertOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRevertOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->mainline = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitRevertOptions::GetMergeOpts) {

      GitRevertOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRevertOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->merge_opts));

     }

    NAN_SETTER(GitRevertOptions::SetMergeOpts) {

      GitRevertOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRevertOptions>(info.This());

        Local<Object> merge_opts(value->ToObject());

        wrapper->merge_opts.Reset(merge_opts);

        wrapper->raw->merge_opts = *  Nan::ObjectWrap::Unwrap<GitMergeOptions>(merge_opts->ToObject())->GetValue() ;

     }

      NAN_GETTER(GitRevertOptions::GetCheckoutOpts) {

      GitRevertOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRevertOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->checkout_opts));

     }

    NAN_SETTER(GitRevertOptions::SetCheckoutOpts) {

      GitRevertOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRevertOptions>(info.This());

        Local<Object> checkout_opts(value->ToObject());

        wrapper->checkout_opts.Reset(checkout_opts);

        wrapper->raw->checkout_opts = *  Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(checkout_opts->ToObject())->GetValue() ;

     }

   
Nan::Persistent<Function> GitRevertOptions::constructor_template;
