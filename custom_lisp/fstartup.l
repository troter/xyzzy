;;; -*-Lisp-*-
;;;
;;; This file is part of xyzzy.
;;;

; (si:*load-library "loadup")

(provide "startup-frame")

(defun si:*startup-frame ()
  (ed::startup-frame))

;(unless (xyzzy-dumped-p)
;  (si:*show-window-foreground)
;  (ed::init-misc-objects)
;  (lisp::snarf-documentation)
;  (dump-xyzzy))

(si:*startup-frame)
