// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/tree.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/oid.h"
  #include "../include/tree_entry.h"
  #include "../include/object.h"
  #include "../include/repository.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitTree::GitTree(git_tree *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitTree::~GitTree() {
      if (this->selfFreeing) {
        git_tree_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                                       }

  void GitTree::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Tree").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "entryById", EntryByid);
            Nan::SetPrototypeMethod(tpl, "_entryByIndex", EntryByindex);
            Nan::SetPrototypeMethod(tpl, "entryByName", EntryByname);
            Nan::SetPrototypeMethod(tpl, "entryByPath", EntryBypath);
             Nan::SetMethod(tpl, "entryCmp", EntryCmp);
             Nan::SetMethod(tpl, "entryDup", EntryDup);
             Nan::SetMethod(tpl, "entryFilemode", EntryFilemode);
             Nan::SetMethod(tpl, "entryFilemodeRaw", EntryFilemodeRaw);
             Nan::SetMethod(tpl, "entryId", EntryId);
             Nan::SetMethod(tpl, "entryName", EntryName);
             Nan::SetMethod(tpl, "entryToObject", EntryToObject);
             Nan::SetMethod(tpl, "entryType", EntryType);
            Nan::SetPrototypeMethod(tpl, "entryCount", Entrycount);
            Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "id", Id);
             Nan::SetMethod(tpl, "lookup", Lookup);
             Nan::SetMethod(tpl, "lookupPrefix", LookupPrefix);
            Nan::SetPrototypeMethod(tpl, "owner", Owner);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Tree").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitTree::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitTree cannot be instantiated.");
     }

    GitTree* object = new GitTree(static_cast<git_tree *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitTree::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitTree::constructor_template), 2, argv).ToLocalChecked());
  }

  git_tree *GitTree::GetValue() {
    return this->raw;
  }

  git_tree **GitTree::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitTree::ClearValue() {
    this->raw = NULL;
  }

  
/*
   * @param Oid id
     * @return TreeEntry  result    */
NAN_METHOD(GitTree::EntryByid) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
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
   const git_tree_entry * result = git_tree_entry_byid(
Nan::ObjectWrap::Unwrap<GitTree>(info.This())->GetValue()
,from_id
  );

   if (info[0]->IsString()) {
    free((void *)from_id);
  }
  // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitTreeEntry result
       to = GitTreeEntry::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Number idx
     * @return TreeEntry  result    */
NAN_METHOD(GitTree::EntryByindex) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number idx is required.");
  }

// start convert_from_v8 block
  size_t from_idx;
  from_idx = (size_t)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   const git_tree_entry * result = git_tree_entry_byindex(
Nan::ObjectWrap::Unwrap<GitTree>(info.This())->GetValue()
,from_idx
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitTreeEntry result
       to = GitTreeEntry::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String filename
     * @return TreeEntry  result    */
NAN_METHOD(GitTree::EntryByname) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String filename is required.");
  }

// start convert_from_v8 block
  const char * from_filename;

  String::Utf8Value filename(info[0]->ToString());
  from_filename = (const char *) strdup(*filename);
// end convert_from_v8 block
   const git_tree_entry * result = git_tree_entry_byname(
Nan::ObjectWrap::Unwrap<GitTree>(info.This())->GetValue()
,from_filename
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitTreeEntry result
       to = GitTreeEntry::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
    * @param String path
    * @param TreeEntry callback
   */
NAN_METHOD(GitTree::EntryBypath) {

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  if (info.Length() == 1 || !info[1]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  EntryBypathBaton* baton = new EntryBypathBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->root = Nan::ObjectWrap::Unwrap<GitTree>(info.This())->GetValue();
// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[0]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
  baton->path = from_path;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[1]));
  EntryBypathWorker *worker = new EntryBypathWorker(baton, callback);
  worker->SaveToPersistent("root", info.This());
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("path", info[0]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitTree::EntryBypathWorker::Execute() {
  int result = git_tree_entry_bypath(
&baton->out,baton->root,baton->path    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitTree::EntryBypathWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitTreeEntry baton->out
       to = GitTreeEntry::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("path"));
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
        Local<v8::Object> err = Nan::Error("Method entryByPath has thrown an error.")->ToObject();
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

  free((void *)baton->path);

  delete baton;
}

   
/*
 * @param TreeEntry e1
   * @param TreeEntry e2
     * @return Number  result    */
NAN_METHOD(GitTree::EntryCmp) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("TreeEntry e1 is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("TreeEntry e2 is required.");
  }

// start convert_from_v8 block
  const git_tree_entry * from_e1;
  from_e1 = Nan::ObjectWrap::Unwrap<GitTreeEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_tree_entry * from_e2;
  from_e2 = Nan::ObjectWrap::Unwrap<GitTreeEntry>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_tree_entry_cmp(
from_e1
,from_e2
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param TreeEntry dest
   * @param TreeEntry source
     * @return Number  result    */
NAN_METHOD(GitTree::EntryDup) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("TreeEntry dest is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("TreeEntry source is required.");
  }

// start convert_from_v8 block
  git_tree_entry ** from_dest;
  from_dest = Nan::ObjectWrap::Unwrap<GitTreeEntry>(info[0]->ToObject())->GetRefValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_tree_entry * from_source;
  from_source = Nan::ObjectWrap::Unwrap<GitTreeEntry>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_tree_entry_dup(
from_dest
,from_source
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param TreeEntry entry
     * @return Number  result    */
NAN_METHOD(GitTree::EntryFilemode) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("TreeEntry entry is required.");
  }

// start convert_from_v8 block
  const git_tree_entry * from_entry;
  from_entry = Nan::ObjectWrap::Unwrap<GitTreeEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   git_filemode_t result = git_tree_entry_filemode(
from_entry
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param TreeEntry entry
     * @return Number  result    */
NAN_METHOD(GitTree::EntryFilemodeRaw) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("TreeEntry entry is required.");
  }

// start convert_from_v8 block
  const git_tree_entry * from_entry;
  from_entry = Nan::ObjectWrap::Unwrap<GitTreeEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   git_filemode_t result = git_tree_entry_filemode_raw(
from_entry
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param TreeEntry entry
     * @return Oid  result    */
NAN_METHOD(GitTree::EntryId) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("TreeEntry entry is required.");
  }

// start convert_from_v8 block
  const git_tree_entry * from_entry;
  from_entry = Nan::ObjectWrap::Unwrap<GitTreeEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   const git_oid * result = git_tree_entry_id(
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
 * @param TreeEntry entry
     * @return String  result    */
NAN_METHOD(GitTree::EntryName) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("TreeEntry entry is required.");
  }

// start convert_from_v8 block
  const git_tree_entry * from_entry;
  from_entry = Nan::ObjectWrap::Unwrap<GitTreeEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   const char * result = git_tree_entry_name(
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
 * @param Object object_out
   * @param Repository repo
   * @param TreeEntry entry
     * @return Number  result    */
NAN_METHOD(GitTree::EntryToObject) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Object object_out is required.");
  }

  if (info.Length() == 1 || !info[1]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 2 || !info[2]->IsObject()) {
    return Nan::ThrowError("TreeEntry entry is required.");
  }

// start convert_from_v8 block
  git_object ** from_object_out;
  from_object_out = Nan::ObjectWrap::Unwrap<GitObject>(info[0]->ToObject())->GetRefValue();
// end convert_from_v8 block
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[1]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const git_tree_entry * from_entry;
  from_entry = Nan::ObjectWrap::Unwrap<GitTreeEntry>(info[2]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_tree_entry_to_object(
from_object_out
,from_repo
,from_entry
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param TreeEntry entry
     * @return Number  result    */
NAN_METHOD(GitTree::EntryType) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("TreeEntry entry is required.");
  }

// start convert_from_v8 block
  const git_tree_entry * from_entry;
  from_entry = Nan::ObjectWrap::Unwrap<GitTreeEntry>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   git_otype result = git_tree_entry_type(
from_entry
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitTree::Entrycount) {
  Nan::EscapableHandleScope scope;

   size_t result = git_tree_entrycount(
Nan::ObjectWrap::Unwrap<GitTree>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     */
NAN_METHOD(GitTree::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitTree>(info.This())->GetValue() != NULL) {
 git_tree_free(
Nan::ObjectWrap::Unwrap<GitTree>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitTree>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
     * @return Oid  result    */
NAN_METHOD(GitTree::Id) {
  Nan::EscapableHandleScope scope;

   const git_oid * result = git_tree_id(
Nan::ObjectWrap::Unwrap<GitTree>(info.This())->GetValue()
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
  * @param Repository repo
   * @param Oid id
    * @param Tree callback
   */
NAN_METHOD(GitTree::Lookup) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1
    || (!info[1]->IsObject() && !info[1]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 2 || !info[2]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  LookupBaton* baton = new LookupBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const git_oid * from_id;
  if (info[1]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[1]->ToString());
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
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[1]->ToObject())->GetValue();
  }
// end convert_from_v8 block
  baton->id = from_id;
  baton->idNeedsFree = info[1]->IsString();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[2]));
  LookupWorker *worker = new LookupWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("id", info[1]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitTree::LookupWorker::Execute() {
  int result = git_tree_lookup(
&baton->out,baton->repo,baton->id    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitTree::LookupWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitTree baton->out
       to = GitTree::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("id"));
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
        Local<v8::Object> err = Nan::Error("Method lookup has thrown an error.")->ToObject();
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

  if (baton->idNeedsFree) {
    baton->idNeedsFree = false;
    free((void *)baton->id);
  }

  delete baton;
}

  
/*
  * @param Repository repo
   * @param Oid id
   * @param Number len
    * @param Tree callback
   */
NAN_METHOD(GitTree::LookupPrefix) {

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1
    || (!info[1]->IsObject() && !info[1]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 2 || !info[2]->IsNumber()) {
    return Nan::ThrowError("Number len is required.");
  }

  if (info.Length() == 3 || !info[3]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  LookupPrefixBaton* baton = new LookupPrefixBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
  baton->repo = from_repo;
// start convert_from_v8 block
  const git_oid * from_id;
  if (info[1]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[1]->ToString());
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
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[1]->ToObject())->GetValue();
  }
// end convert_from_v8 block
  baton->id = from_id;
  baton->idNeedsFree = info[1]->IsString();
// start convert_from_v8 block
  size_t from_len;
  from_len = (size_t)   info[2]->ToNumber()->Value();
// end convert_from_v8 block
  baton->len = from_len;

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[3]));
  LookupPrefixWorker *worker = new LookupPrefixWorker(baton, callback);
  if (!info[0]->IsUndefined() && !info[0]->IsNull())
    worker->SaveToPersistent("repo", info[0]->ToObject());
  if (!info[1]->IsUndefined() && !info[1]->IsNull())
    worker->SaveToPersistent("id", info[1]->ToObject());
  if (!info[2]->IsUndefined() && !info[2]->IsNull())
    worker->SaveToPersistent("len", info[2]->ToObject());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitTree::LookupPrefixWorker::Execute() {
  int result = git_tree_lookup_prefix(
&baton->out,baton->repo,baton->id,baton->len    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitTree::LookupPrefixWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitTree baton->out
       to = GitTree::New((void *)baton->out, false);
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
      workerArguments.push(GetFromPersistent("id"));
      workerArguments.push(GetFromPersistent("len"));
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
        Local<v8::Object> err = Nan::Error("Method lookupPrefix has thrown an error.")->ToObject();
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

  if (baton->idNeedsFree) {
    baton->idNeedsFree = false;
    free((void *)baton->id);
  }

  delete baton;
}

   
/*
     * @return Repository  result    */
NAN_METHOD(GitTree::Owner) {
  Nan::EscapableHandleScope scope;

   git_repository * result = git_tree_owner(
Nan::ObjectWrap::Unwrap<GitTree>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitRepository result
       to = GitRepository::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitTree::constructor_template;
 