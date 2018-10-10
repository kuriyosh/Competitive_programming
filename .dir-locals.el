;;; .dir-locals.el ---                               -*- lexical-binding: t; -*-

;; Copyright (C) 2018  torith

;; Author: torith
;; Keywords:
;; TODO: これではだめ
(auto-insert-mode . (
					 (setq auto-insert-directory "./template/")
					 (setq auto-insert-alist '(("\\.cpp$" . ["comptemp.cpp" my-template])))
					 ))

(provide 'dir-locals)
;;; dir-locals.el ends here

