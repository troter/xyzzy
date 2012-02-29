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

(deftest fix-list-all-packages-test ()
  "(list-all-packages) should return 'a copy of' system package list."
  (let* ((name :temporary-package-for-test)
	 (pkg (make-package name))
	 (pkglist (list-all-packages)))
    (delete pkg pkglist)
    (eq pkg (find-package name)))
  => t)
