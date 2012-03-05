;; need docstring support!
(deftest fix-previous-pseudo-frame-test ()
  "(previous-pseudo-frame) caused \"appframe not found\" error."
  (previous-pseudo-frame)
  => nil)


;; (make-frame) create strange scratch buffer
;(deftest fix-multiframe-create-strange-buffer-test ()
;; make frame asis cause split-window problem.
;; So I comment out this test now.
(defun dummy-fix-multiframe-create-strange-buffer-test ()
  (let* ((org (length (buffer-list)))
	 frame res)
    (setq frame (make-frame))
    (setq res (= org (length (buffer-list))))
    ;; changing selected-frame cause problem.
    ;; (delete-frame frame)
    res)
  => t)

(defun make-test-package (&rest options)
  (let ((name (format nil "temporary-package-for-test-~D" (test-uid))))
    (apply #'make-package name options)))

(deftest fix-list-all-packages-test ()
  "(list-all-packages) should return 'a copy of' system package list."
  (let* ((pkg (make-test-package))
         (name (package-name pkg))
	 (pkglist (list-all-packages)))
    (delete pkg pkglist)
    (eq pkg (find-package name)))
  => t)
