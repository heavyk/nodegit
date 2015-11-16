// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/reflog.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/oid.h"
  #include "../include/signature.h"
  #include "../include/repository.h"
  #include "../include/reflog_entry.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitReflog::GitReflog(git_reflog *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitReflog::~GitReflog() {
      if (this->selfFreeing) {
        git_reflog_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                     }

  void GitReflog::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Reflog").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "append", Append);
             Nan::SetMethod(tpl, "delete", Delete);
            Nan::SetPrototypeMethod(tpl, "drop", Drop);
            Nan::SetPrototypeMethod(tpl, "entryByIndex", EntryByindex);
             Nan::SetMethod(tpl, "entryCommitter", EntryCommitter);
             Nan::SetMethod(tpl, "entryIdNew", EntryIdNew);
             Nan::SetMethod(tpl, "entryIdOld", EntryIdOld);
             Nan::SetMethod(tpl, "entryMessage", EntryMessage);
            Nan::SetPrototypeMethod(tpl, "entrycount", Entrycount);
            Nan::SetPrototypeMethod(tpl, "free", Free);
             Nan::SetMethod(tpl, "read", Read);
             Nan::SetMethod(tpl, "rename", Rename);
            Nan::SetPrototypeMethod(tpl, "write", Write);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Reflog").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitReflog::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitReflog cannot be instantiated.");
     }

    GitReflog* object = new GitReflog(static_cast<git_reflog *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitReflog::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitReflog::constructor_template), 2, argv).ToLocalChecked());
  }

  git_reflog *GitReflog::GetValue() {
    return this->raw;
  }

  git_reflog **GitReflog::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitReflog::ClearValue() {
    this->raw = NULL;
  }

  
/*
   * @param Oid id
   * @param Signature committer
   * @param String msg
     * @return Number  result    */
NAN_METHOD(GitReflog::Append) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Signature committer is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String msg is required.");
  }

// start convert_from_v8 block
  const git_oid * from_id;
  if (info[0]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[0]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_id = oidOut;
  }
  else {
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const git_signature * from_committer;
  from_committer = Nan::ObjectWrap::Unwrap<GitSignature>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_msg;

  String::Utf8Value msg(info[2]->ToString());
  from_msg = (const char *) strdup(*msg);
// end convert_from_v8 block
   int result = git_reflog_append(
Nan::ObjectWrap::Unwrap<GitReflog>(info.This())->GetValue()
,from_id
,from_committer
,from_msg
  );

   if (info[0]->IsString()) {
    free((void *)from_id);
  }

  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param Repository repo
   * @param String name
     * @return Number  result    */
NAN_METHOD(GitReflog::Delete) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[1]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
   int result = git_reflog_delete(
from_repo
,from_name
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Number idx
   * @param Number rewrite_previous_entry
     * @return Number  result    */
NAN_METHOD(GitReflog::Drop) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number idx is required.");
  }

  if (info.Length() == 1 || !info[1]->IsNumber()) {
    return Nan::ThrowError("Number rewrite_previous_entry is required.");
  }

// start convert_from_v8 block
  size_t from_idx;
  from_idx = (size_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  int from_rewrite_previous_entry;
  from_rewrite_previous_entry = (int)   info[1]->ToNumber()->Value();
// end convert_from_v8 block
   int result = git_reflog_drop(
Nan::ObjectWrap::Unwrap<GitReflog>(info.This())->GetValue()
,from_idx
,from_rewrite_previous_entry
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Number idx
     * @return ReflogEntry  result    */
NAN_METHOD(GitReflog::EntryByindex) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number idx is required.");
  }

// start convert_from_v8 block
  size_t from_idx;
  from_idx = (size_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   const git_reflog_entry * result = git_reflog_entry_byindex(
Nan::ObjectWrap::Unwrap<GitReflog>(info.This())->GetValue()
,from_idx
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitReflogEntry result
       to = GitReflogEntry::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param ReflogEntry entry
     * @return Signature  result    */
NAN_METHOD(GitReflog::EntryCommitter) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("ReflogEntry entry is required.");
  }

// start convert_from_v8 block
  const git_reflog_entry * from_entry;
  from_entry = Nan::ObjectWrap::Unwrap<GitReflogEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   const git_signature * result = git_reflog_entry_committer(
from_entry
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitSignature result
       to = GitSignature::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param ReflogEntry entry
     * @return Oid  result    */
NAN_METHOD(GitReflog::EntryIdNew) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("ReflogEntry entry is required.");
  }

// start convert_from_v8 block
  const git_reflog_entry * from_entry;
  from_entry = Nan::ObjectWrap::Unwrap<GitReflogEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   const git_oid * result = git_reflog_entry_id_new(
from_entry
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitOid result
       to = GitOid::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param ReflogEntry entry
     * @return Oid  result    */
NAN_METHOD(GitReflog::EntryIdOld) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("ReflogEntry entry is required.");
  }

// start convert_from_v8 block
  const git_reflog_entry * from_entry;
  from_entry = Nan::ObjectWrap::Unwrap<GitReflogEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   const git_oid * result = git_reflog_entry_id_old(
from_entry
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitOid result
       to = GitOid::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param ReflogEntry entry
     * @return String  result    */
NAN_METHOD(GitReflog::EntryMessage) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("ReflogEntry entry is required.");
  }

// start convert_from_v8 block
  const git_reflog_entry * from_entry;
  from_entry = Nan::ObjectWrap::Unwrap<GitReflogEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   const char * result = git_reflog_entry_message(
from_entry
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  if (result){
       to = Nan::New<String>(result).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitReflog::Entrycount) {
  Nan::EscapableHandleScope scope;

   size_t result = git_reflog_entrycount(
Nan::ObjectWrap::Unwrap<GitReflog>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     */
NAN_METHOD(GitReflog::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitReflog>(info.This())->GetValue() != NULL) {
 git_reflog_free(
Nan::ObjectWrap::Unwrap<GitReflog>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitReflog>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
  
/*
  * @param Repository repo
   * @param String name
    * @param Reflog callback
   */
NAN_METHOD(GitReflog::Read) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  ReadBaton* baton = new ReadBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[1]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
  baton->name = from_name;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  ReadWorker *worker = new ReadWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("name", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitReflog::ReadWorker::Execute() {
  int result = git_reflog_read(
&baton->out,baton->repo,baton->name    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitReflog::ReadWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitReflog baton->out
       to = GitReflog::New((void *)baton->out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      workerArguments.push(GetFromPersistent("repo"));
      workerArguments.push(GetFromPersistent("name"));
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method read has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }

  free((void *)baton->name);

  delete baton;
}

   
/*
 * @param Repository repo
   * @param String old_name
   * @param String name
     * @return Number  result    */
NAN_METHOD(GitReflog::Rename) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String old_name is required.");
  }

  if (info.Length() == 2 || !info[2]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_old_name;

  String::Utf8Value old_name(info[1]->ToString());
  from_old_name = (const char *) strdup(*old_name);
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[2]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
   int result = git_reflog_rename(
from_repo
,from_old_name
,from_name
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitReflog::Write) {
  Nan::EscapableHandleScope scope;

   int result = git_reflog_write(
Nan::ObjectWrap::Unwrap<GitReflog>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitReflog::constructor_template;
 