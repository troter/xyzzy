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

(defmacro with-moved-p (&body body)
  `(let* ((#1=#:point (point)))
     (save-excursion
       ,@body
       (not (eq #1# (point))))))

(defmacro with-c++-bed (&body body)
  `(with-temp-buffer
    (c++-mode)
    ,@body
    ))

(deftest fix-parenthesis-escape-case-forward ()
  "cc mode goto-matched parentheis does not understand escape for hanlding comment"
  (with-c++-bed
   (insert "(hoge\\//)")
   (goto-char 0)
   (with-moved-p
    (goto-matched-parenthesis)))
  => t)

(deftest fix-parenthesis-escape-case-backward ()
  "cc mode goto-matched parentheis does not understand escape for hanlding comment, backward"
  (with-c++-bed
   (insert "(hoge\\//)")
   (end-of-buffer)
   (backward-char)
   (with-moved-p
    (goto-matched-parenthesis)))
  => t)

(deftest fix-parenthesis-no-escape-case-forward ()
  "cc mode goto-matched parentheis does not understand escape for hanlding comment, not escape case"
  (with-c++-bed
   (insert "(hoge\\\\//)")
   (goto-char 0)
   (with-moved-p
    (goto-matched-parenthesis)))
  => nil)

(deftest fix-parenthesis-no-escape-case-backward ()
  "cc mode goto-matched parentheis does not understand escape for hanlding comment, not escape case, backward"
  (with-c++-bed
   (insert "(hoge\\\\//)")
   (end-of-buffer)
   (backward-char)
   (with-moved-p
    (goto-matched-parenthesis)))
  => nil)

