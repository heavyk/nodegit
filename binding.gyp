# // This is a generated file, modify: generate/templates/binding.gyp.

{
  "targets": [{
    "target_name": "nodegit",

    "dependencies": [
      "vendor/libgit2.gyp:libgit2"
    ],

    "variables": {
      "coverage%": 0
    },

    "sources": [
      "src/nodegit.cc",
      "src/wrapper.cc",
      "src/functions/copy.cc",
      "src/functions/sleep_for_ms.cc",
      "src/str_array_converter.cc",
      "src/annotated_commit.cc",
      "src/attr.cc",
      "src/blame.cc",
      "src/blame_hunk.cc",
      "src/blame_options.cc",
      "src/blob.cc",
      "src/branch.cc",
      "src/branch_iterator.cc",
      "src/buf.cc",
      "src/cert.cc",
      "src/cert_hostkey.cc",
      "src/cert_x509.cc",
      "src/checkout.cc",
      "src/checkout_options.cc",
      "src/cherrypick.cc",
      "src/cherrypick_options.cc",
      "src/clone.cc",
      "src/clone_options.cc",
      "src/commit.cc",
      "src/config.cc",
      "src/config_entry.cc",
      "src/config_entry.cc",
      "src/cred.cc",
      "src/cred_default.cc",
      "src/cred_username.cc",
      "src/cred_userpass_payload.cc",
      "src/cvar_map.cc",
      "src/describe_format_options.cc",
      "src/describe_options.cc",
      "src/diff.cc",
      "src/diff_binary.cc",
      "src/diff_binary_file.cc",
      "src/diff_delta.cc",
      "src/diff_file.cc",
      "src/diff_find_options.cc",
      "src/diff_hunk.cc",
      "src/diff_line.cc",
      "src/diff_options.cc",
      "src/diff_options.cc",
      "src/diff_perfdata.cc",
      "src/diff_perfdata.cc",
      "src/diff_stats.cc",
      "src/error.cc",
      "src/fetch.cc",
      "src/fetch_options.cc",
      "src/fetch_options.cc",
      "src/filter.cc",
      "src/filter.cc",
      "src/filter_list.cc",
      "src/giterr.cc",
      "src/graph.cc",
      "src/hashsig.cc",
      "src/ignore.cc",
      "src/index.cc",
      "src/index_conflict_iterator.cc",
      "src/index_entry.cc",
      "src/index_time.cc",
      "src/indexer.cc",
      "src/libgit2.cc",
      "src/mempack.cc",
      "src/merge.cc",
      "src/merge_file_input.cc",
      "src/merge_file_options.cc",
      "src/merge_file_result.cc",
      "src/merge_options.cc",
      "src/merge_options.cc",
      "src/merge_result.cc",
      "src/message.cc",
      "src/note.cc",
      "src/note_iterator.cc",
      "src/object.cc",
      "src/odb.cc",
      "src/odb_object.cc",
      "src/oid.cc",
      "src/oid_shorten.cc",
      "src/oidarray.cc",
      "src/openssl.cc",
      "src/packbuilder.cc",
      "src/patch.cc",
      "src/pathspec.cc",
      "src/pathspec_match_list.cc",
      "src/push.cc",
      "src/push_options.cc",
      "src/push_update.cc",
      "src/rebase.cc",
      "src/rebase_operation.cc",
      "src/rebase_options.cc",
      "src/refdb.cc",
      "src/reference.cc",
      "src/reflog.cc",
      "src/reflog_entry.cc",
      "src/refspec.cc",
      "src/remote.cc",
      "src/remote_callbacks.cc",
      "src/remote_callbacks.cc",
      "src/repository.cc",
      "src/repository_init_options.cc",
      "src/reset.cc",
      "src/revert.cc",
      "src/revert_options.cc",
      "src/revparse.cc",
      "src/revwalk.cc",
      "src/signature.cc",
      "src/smart.cc",
      "src/stash.cc",
      "src/stash_apply_options.cc",
      "src/status.cc",
      "src/status_entry.cc",
      "src/status_list.cc",
      "src/status_options.cc",
      "src/strarray.cc",
      "src/submodule.cc",
      "src/submodule_update_options.cc",
      "src/tag.cc",
      "src/time.cc",
      "src/trace.cc",
      "src/transaction.cc",
      "src/transfer_progress.cc",
      "src/transport.cc",
      "src/tree.cc",
      "src/tree_entry.cc",
      "src/treebuilder.cc",
      "src/writestream.cc",
    ],

    "include_dirs": [
      "vendor/libv8-convert",
      "<!(node -e \"require('nan')\")"
    ],

    "cflags": [
      "-Wall"
    ],

    "conditions": [
      [
        "coverage==1", {
          "cflags": [
            "-ftest-coverage",
            "-fprofile-arcs"
          ],
          "link_settings": {
            "libraries": [
              "-lgcov"
            ]
          },
        }
      ],
      [
        "OS=='mac'", {
          "xcode_settings": {
            "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
            "MACOSX_DEPLOYMENT_TARGET": "10.7",

            "WARNING_CFLAGS": [
              "-Wno-unused-variable",
              "-Wint-conversions",
              "-Wmissing-field-initializers"
            ]
          }
        }
      ],
      [
        "OS=='win'", {
          "cflags": [
            "/EHsc"
          ],
          "defines": [
            "_HAS_EXCEPTIONS=1"
          ]
        }
      ]
    ]
  }]
}