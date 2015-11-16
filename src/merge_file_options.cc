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
#include "../include/merge_file_options.h"
#include "../include/functions/sleep_for_ms.h"

 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitMergeFileOptions::GitMergeFileOptions() {
   git_merge_file_options wrappedValue = GIT_MERGE_FILE_OPTIONS_INIT;
   this->raw = (git_merge_file_options*) malloc(sizeof(git_merge_file_options));
  memcpy(this->raw, &wrappedValue, sizeof(git_merge_file_options));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitMergeFileOptions::GitMergeFileOptions(git_merge_file_options* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitMergeFileOptions::~GitMergeFileOptions() {
                    
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitMergeFileOptions::ConstructFields() {
                  }

void GitMergeFileOptions::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("MergeFileOptions").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("ancestorLabel").ToLocalChecked(), GetAncestorLabel, SetAncestorLabel);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("ourLabel").ToLocalChecked(), GetOurLabel, SetOurLabel);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("theirLabel").ToLocalChecked(), GetTheirLabel, SetTheirLabel);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("favor").ToLocalChecked(), GetFavor, SetFavor);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("flags").ToLocalChecked(), GetFlags, SetFlags);
   
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("MergeFileOptions").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitMergeFileOptions::JSNewFunction) {
  GitMergeFileOptions* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitMergeFileOptions();
  }
  else {
    instance = new GitMergeFileOptions(static_cast<git_merge_file_options*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitMergeFileOptions::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitMergeFileOptions::constructor_template), 2, argv).ToLocalChecked());
}

git_merge_file_options *GitMergeFileOptions::GetValue() {
  return this->raw;
}

git_merge_file_options **GitMergeFileOptions::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitMergeFileOptions::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitMergeFileOptions::GetVersion) {

      GitMergeFileOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitMergeFileOptions::SetVersion) {

      GitMergeFileOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitMergeFileOptions::GetAncestorLabel) {

      GitMergeFileOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileOptions>(info.This());

        if (wrapper->GetValue()->ancestor_label) {
          info.GetReturnValue().Set(Nan::New<String>(wrapper->GetValue()->ancestor_label).ToLocalChecked());
        }
        else {
          return;
        }

     }

    NAN_SETTER(GitMergeFileOptions::SetAncestorLabel) {

      GitMergeFileOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileOptions>(info.This());

        if (wrapper->GetValue()->ancestor_label) {
        }

        String::Utf8Value str(value);
        wrapper->GetValue()->ancestor_label = strdup(*str);

     }

      NAN_GETTER(GitMergeFileOptions::GetOurLabel) {

      GitMergeFileOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileOptions>(info.This());

        if (wrapper->GetValue()->our_label) {
          info.GetReturnValue().Set(Nan::New<String>(wrapper->GetValue()->our_label).ToLocalChecked());
        }
        else {
          return;
        }

     }

    NAN_SETTER(GitMergeFileOptions::SetOurLabel) {

      GitMergeFileOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileOptions>(info.This());

        if (wrapper->GetValue()->our_label) {
        }

        String::Utf8Value str(value);
        wrapper->GetValue()->our_label = strdup(*str);

     }

      NAN_GETTER(GitMergeFileOptions::GetTheirLabel) {

      GitMergeFileOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileOptions>(info.This());

        if (wrapper->GetValue()->their_label) {
          info.GetReturnValue().Set(Nan::New<String>(wrapper->GetValue()->their_label).ToLocalChecked());
        }
        else {
          return;
        }

     }

    NAN_SETTER(GitMergeFileOptions::SetTheirLabel) {

      GitMergeFileOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileOptions>(info.This());

        if (wrapper->GetValue()->their_label) {
        }

        String::Utf8Value str(value);
        wrapper->GetValue()->their_label = strdup(*str);

     }

      NAN_GETTER(GitMergeFileOptions::GetFavor) {

      GitMergeFileOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileOptions>(info.This());

        info.GetReturnValue().Set(Nan::New((int)wrapper->GetValue()->favor));

     }

    NAN_SETTER(GitMergeFileOptions::SetFavor) {

      GitMergeFileOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileOptions>(info.This());

        if (value->IsNumber()) {
          wrapper->GetValue()->favor = (git_merge_file_favor_t) Nan::To<int32_t>(value).FromJust();
        }

     }

      NAN_GETTER(GitMergeFileOptions::GetFlags) {

      GitMergeFileOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileOptions>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->flags));
     }

    NAN_SETTER(GitMergeFileOptions::SetFlags) {

      GitMergeFileOptions *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileOptions>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->flags = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

   
Nan::Persistent<Function> GitMergeFileOptions::constructor_template;
