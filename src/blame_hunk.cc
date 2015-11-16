// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/blame_hunk.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/oid.h"
  #include "../include/signature.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitBlameHunk::GitBlameHunk(git_blame_hunk *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitBlameHunk::~GitBlameHunk() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitBlameHunk::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("BlameHunk").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "linesInHunk", LinesInHunk);
         Nan::SetPrototypeMethod(tpl, "finalCommitId", FinalCommitId);
         Nan::SetPrototypeMethod(tpl, "finalStartLineNumber", FinalStartLineNumber);
         Nan::SetPrototypeMethod(tpl, "finalSignature", FinalSignature);
         Nan::SetPrototypeMethod(tpl, "origCommitId", OrigCommitId);
         Nan::SetPrototypeMethod(tpl, "origPath", OrigPath);
         Nan::SetPrototypeMethod(tpl, "origStartLineNumber", OrigStartLineNumber);
         Nan::SetPrototypeMethod(tpl, "origSignature", OrigSignature);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("BlameHunk").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitBlameHunk::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitBlameHunk cannot be instantiated.");
     }

    GitBlameHunk* object = new GitBlameHunk(static_cast<git_blame_hunk *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitBlameHunk::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitBlameHunk::constructor_template), 2, argv).ToLocalChecked());
  }

  git_blame_hunk *GitBlameHunk::GetValue() {
    return this->raw;
  }

  git_blame_hunk **GitBlameHunk::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitBlameHunk::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitBlameHunk::LinesInHunk) {
      Local<v8::Value> to;

       uint16_t
         lines_in_hunk =
         Nan::ObjectWrap::Unwrap<GitBlameHunk>(info.This())->GetValue()->lines_in_hunk;
 // start convert_to_v8 block
     to = Nan::New<Number>( lines_in_hunk);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitBlameHunk::FinalCommitId) {
      Local<v8::Value> to;

       git_oid
        *
          final_commit_id =
        &
          Nan::ObjectWrap::Unwrap<GitBlameHunk>(info.This())->GetValue()->final_commit_id;
 // start convert_to_v8 block
  
  if (final_commit_id != NULL) {
    // GitOid final_commit_id
       to = GitOid::New((void *)final_commit_id, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitBlameHunk::FinalStartLineNumber) {
      Local<v8::Value> to;

       uint16_t
         final_start_line_number =
         Nan::ObjectWrap::Unwrap<GitBlameHunk>(info.This())->GetValue()->final_start_line_number;
 // start convert_to_v8 block
     to = Nan::New<Number>( final_start_line_number);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitBlameHunk::FinalSignature) {
      Local<v8::Value> to;

       git_signature *
          final_signature =
          Nan::ObjectWrap::Unwrap<GitBlameHunk>(info.This())->GetValue()->final_signature;
 // start convert_to_v8 block
  
  if (final_signature != NULL) {
    // GitSignature final_signature
       to = GitSignature::New((void *)final_signature, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitBlameHunk::OrigCommitId) {
      Local<v8::Value> to;

       git_oid
        *
          orig_commit_id =
        &
          Nan::ObjectWrap::Unwrap<GitBlameHunk>(info.This())->GetValue()->orig_commit_id;
 // start convert_to_v8 block
  
  if (orig_commit_id != NULL) {
    // GitOid orig_commit_id
       to = GitOid::New((void *)orig_commit_id, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitBlameHunk::OrigPath) {
      Local<v8::Value> to;

       const char *
         orig_path =
         Nan::ObjectWrap::Unwrap<GitBlameHunk>(info.This())->GetValue()->orig_path;
 // start convert_to_v8 block
  if (orig_path){
       to = Nan::New<String>(orig_path).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitBlameHunk::OrigStartLineNumber) {
      Local<v8::Value> to;

       uint16_t
         orig_start_line_number =
         Nan::ObjectWrap::Unwrap<GitBlameHunk>(info.This())->GetValue()->orig_start_line_number;
 // start convert_to_v8 block
     to = Nan::New<Number>( orig_start_line_number);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitBlameHunk::OrigSignature) {
      Local<v8::Value> to;

       git_signature *
          orig_signature =
          Nan::ObjectWrap::Unwrap<GitBlameHunk>(info.This())->GetValue()->orig_signature;
 // start convert_to_v8 block
  
  if (orig_signature != NULL) {
    // GitSignature orig_signature
       to = GitSignature::New((void *)orig_signature, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitBlameHunk::constructor_template;
 