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
#include "../include/rebase_options.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/checkout_options.h"
 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitRebaseOptions::GitRebaseOptions() {
   git_rebase_options wrappedValue = GIT_REBASE_OPTIONS_INIT;
   this->raw = (git_rebase_options*) malloc(sizeof(git_rebase_options));
  memcpy(this->raw, &wrappedValue, sizeof(git_rebase_options));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitRebaseOptions::GitRebaseOptions(git_rebase_options* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitRebaseOptions::~GitRebaseOptions() {
               
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitRebaseOptions::ConstructFields() {
                   Local<Object> checkout_optionsTemp = GitCheckoutOptions::New(
            &this->raw->checkout_options,
            false
          )->ToObject();
          this->checkout_options.Reset(checkout_optionsTemp);

    }

void GitRebaseOptions::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("RebaseOptions").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("quiet").ToLocalChecked(), GetQuiet, SetQuiet);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("rewriteNotesRef").ToLocalChecked(), GetRewriteNotesRef, SetRewriteNotesRef);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("checkoutOptions").ToLocalChecked(), GetCheckoutOptions, SetCheckoutOptions);
   
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("RebaseOptions").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitRebaseOptions::JSNewFunction) {
  GitRebaseOptions* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitRebaseOptions();
  }
  else {
    instance = new GitRebaseOptions(static_cast<git_rebase_options*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitRebaseOptions::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitRebaseOptions::constructor_template), 2, argv).ToLocalChecked());
}

git_rebase_options *GitRebaseOptions::GetValue() {
  return this->raw;
}

git_rebase_options **GitRebaseOptions::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitRebaseOptions::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitRebaseOptions::GetVersion) {

      GitRebaseOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRebaseOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitRebaseOptions::SetVersion) {

      GitRebaseOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRebaseOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitRebaseOptions::GetQuiet) {

      GitRebaseOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRebaseOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->quiet));
     }

    NAN_SETTER(GitRebaseOptions::SetQuiet) {

      GitRebaseOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRebaseOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->quiet = (int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitRebaseOptions::GetRewriteNotesRef) {

      GitRebaseOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRebaseOptions>(info.This());

        if (wrapper->GetValue()->rewrite_notes_ref) {
          info.GetReturnValue().Set(Nan::New<String>(wrapper->GetValue()->rewrite_notes_ref).ToLocalChecked());
        }
        else {
          return;
        }

     }

    NAN_SETTER(GitRebaseOptions::SetRewriteNotesRef) {

      GitRebaseOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRebaseOptions>(info.This());

        if (wrapper->GetValue()->rewrite_notes_ref) {
        }

        String::Utf8Value str(value);
        wrapper->GetValue()->rewrite_notes_ref = strdup(*str);

     }

      NAN_GETTER(GitRebaseOptions::GetCheckoutOptions) {

      GitRebaseOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRebaseOptions>(info.This());

        info.GetReturnValue().Set(Nan::New(wrapper->checkout_options));

     }

    NAN_SETTER(GitRebaseOptions::SetCheckoutOptions) {

      GitRebaseOptions *wrapper = Nan::ObjectWrap::Unwrap<GitRebaseOptions>(info.This());

        Local<Object> checkout_options(value->ToObject());

        wrapper->checkout_options.Reset(checkout_options);

        wrapper->raw->checkout_options = *  Nan::ObjectWrap::Unwrap<GitCheckoutOptions>(checkout_options->ToObject())->GetValue() ;

     }

   
Nan::Persistent<Function> GitRebaseOptions::constructor_template;
