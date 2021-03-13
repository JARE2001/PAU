#lang racket

;; A01701350 Jorge Alan Ramirez Elias
;; A01701490 Paulina Cardoso Fuentes

;; Insert
(define (insert n lst)
  (cond
    [(empty? lst) n]
    [(< n (car lst)) (cons n lst)]
    [else (insert n (cdr lst))]))