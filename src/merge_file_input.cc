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
#include "../include/merge_file_input.h"
#include "../include/functions/sleep_for_ms.h"

 
using namespace v8;
using namespace node;
using namespace std;


// generated from struct_content.cc
GitMergeFileInput::GitMergeFileInput() {
   git_merge_file_input wrappedValue = GIT_MERGE_FILE_INPUT_INIT;
   this->raw = (git_merge_file_input*) malloc(sizeof(git_merge_file_input));
  memcpy(this->raw, &wrappedValue, sizeof(git_merge_file_input));

  this->ConstructFields();
  this->selfFreeing = true;
}

GitMergeFileInput::GitMergeFileInput(git_merge_file_input* raw, bool selfFreeing) {
  this->raw = raw;
  this->ConstructFields();
  this->selfFreeing = selfFreeing;
}

GitMergeFileInput::~GitMergeFileInput() {
                  
  if (this->selfFreeing) {
    free(this->raw);
  }
}

void GitMergeFileInput::ConstructFields() {
                }

void GitMergeFileInput::InitializeComponent(Local<v8::Object> target) {
  Nan::HandleScope scope;

  Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(Nan::New("MergeFileInput").ToLocalChecked());

      Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("version").ToLocalChecked(), GetVersion, SetVersion);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("ptr").ToLocalChecked(), GetPtr, SetPtr);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("size").ToLocalChecked(), GetSize, SetSize);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("path").ToLocalChecked(), GetPath, SetPath);
        Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("mode").ToLocalChecked(), GetMode, SetMode);
   
  Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
  constructor_template.Reset(_constructor_template);
  Nan::Set(target, Nan::New("MergeFileInput").ToLocalChecked(), _constructor_template);
}

NAN_METHOD(GitMergeFileInput::JSNewFunction) {
  GitMergeFileInput* instance;

  if (info.Length() == 0 || !info[0]->IsExternal()) {
    instance = new GitMergeFileInput();
  }
  else {
    instance = new GitMergeFileInput(static_cast<git_merge_file_input*>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
  }

  instance->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}

Local<v8::Value> GitMergeFileInput::New(void* raw, bool selfFreeing) {
  Nan::EscapableHandleScope scope;

  Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New<Boolean>(selfFreeing) };
  return scope.Escape(Nan::NewInstance(Nan::New(GitMergeFileInput::constructor_template), 2, argv).ToLocalChecked());
}

git_merge_file_input *GitMergeFileInput::GetValue() {
  return this->raw;
}

git_merge_file_input **GitMergeFileInput::GetRefValue() {
  return this->raw == NULL ? NULL : &this->raw;
}

void GitMergeFileInput::ClearValue() {
  this->raw = NULL;
}

    NAN_GETTER(GitMergeFileInput::GetVersion) {

      GitMergeFileInput *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileInput>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->version));
     }

    NAN_SETTER(GitMergeFileInput::SetVersion) {

      GitMergeFileInput *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileInput>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->version = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitMergeFileInput::GetPtr) {

      GitMergeFileInput *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileInput>(info.This());

        if (wrapper->GetValue()->ptr) {
          info.GetReturnValue().Set(Nan::New<String>(wrapper->GetValue()->ptr).ToLocalChecked());
        }
        else {
          return;
        }

     }

    NAN_SETTER(GitMergeFileInput::SetPtr) {

      GitMergeFileInput *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileInput>(info.This());

        if (wrapper->GetValue()->ptr) {
        }

        String::Utf8Value str(value);
        wrapper->GetValue()->ptr = strdup(*str);

     }

      NAN_GETTER(GitMergeFileInput::GetSize) {

      GitMergeFileInput *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileInput>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->size));
     }

    NAN_SETTER(GitMergeFileInput::SetSize) {

      GitMergeFileInput *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileInput>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->size = (size_t) Nan::To<int32_t>(value).FromJust();
        }
     }

      NAN_GETTER(GitMergeFileInput::GetPath) {

      GitMergeFileInput *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileInput>(info.This());

        if (wrapper->GetValue()->path) {
          info.GetReturnValue().Set(Nan::New<String>(wrapper->GetValue()->path).ToLocalChecked());
        }
        else {
          return;
        }

     }

    NAN_SETTER(GitMergeFileInput::SetPath) {

      GitMergeFileInput *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileInput>(info.This());

        if (wrapper->GetValue()->path) {
        }

        String::Utf8Value str(value);
        wrapper->GetValue()->path = strdup(*str);

     }

      NAN_GETTER(GitMergeFileInput::GetMode) {

      GitMergeFileInput *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileInput>(info.This());

        info.GetReturnValue().Set(Nan::New<Number>(wrapper->GetValue()->mode));
     }

    NAN_SETTER(GitMergeFileInput::SetMode) {

      GitMergeFileInput *wrapper = Nan::ObjectWrap::Unwrap<GitMergeFileInput>(info.This());

         if (value->IsNumber()) {
          wrapper->GetValue()->mode = (unsigned int) Nan::To<int32_t>(value).FromJust();
        }
     }

   
Nan::Persistent<Function> GitMergeFileInput::constructor_template;
