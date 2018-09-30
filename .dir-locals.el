;;; .dir-locals.el ---                               -*- lexical-binding: t; -*-

;; Copyright (C) 2018  torith

;; Author: torith
;; Keywords:
(require 'autoinsert)
(setq auto-insert-directory "template")
(setq auto-insert-alist
      (append '(("\\.cpp$" . ["comptemp.cpp"])) auto-insert-alist))
(add-hook 'find-file-not-found-hooks 'auto-insert)

(provide 'dir-locals)
;;; dir-locals.el ends here
