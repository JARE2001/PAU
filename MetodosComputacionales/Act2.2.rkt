#lang racket

;; A01701350 Jorge Alan Ramirez Elias
;; A01701490 Paulina Cardoso Fuentes

;; Insert
(define (insert n lst)
  (cond
    [(empty? lst) (cons n lst)]
    [(< n (car lst)) (cons n lst)]
    [else (cons (car lst) (insert n (cdr lst)))]))


;; Insertion sort
(define (insertion-sort lst)
   (cond
     [(empty? lst) '()]
     [else (insert (car lst) (insertion-sort (cdr lst)))]))


;; Last element
(define (last lst)
  (cond
    [(empty? (cdr lst)) (car lst)]
    [else (last (cdr lst))]))


;; El resto menos el last
(define (minus-last lst)
  (cond
    [(empty? (cdr lst)) '()]
    [else (append (list(car lst)) (minus-last (cdr lst)))]))


;; Rotate-left
(define (rotate-left n lst)
  (cond
    [(empty? lst) '()]
    [(eq? n 0) lst]
    [(> n 0) (rotate-left (- n 1) (append (cdr lst) (list (car lst))))]
    [(< n 0) (rotate-left (+ n 1) (append (list (last lst)) (minus-last lst)))]))



;; Primer factors
;(define (prime-factors n)
;  (cond
;    [(eq? 0 (remainder (/ n i))) (cons i (prime-factors (/ n i)))]
;    [else ]))


;; GCD
;(define (gcd a b))