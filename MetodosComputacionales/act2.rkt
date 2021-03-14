#lang racket
(define ( sum a b)
  (+ a b))
(define (isTwo x)
  (cond
    [(= x 2)true]
    [else false]))


(define (push-before-last lst x)
  (cond
    [(empty? (cdr lst)) (list  x (car lst))]
    [else (append (list(car lst)) (push-before-last (cdr lst) x))]))


(define (insert-everywhere x lst)
  (cond
    [(empty? lst) (list x)]
    [(not(list? x)) (cons (append (list x) lst) (insert-everywhere (append (list(car lst)) (list x)) (cdr lst))) ]
    [else(cons (append x lst) (insert-everywhere (push-before-last x (car lst))  (cdr lst))) ]))

(define (iguales act lst)
  (cond
    [(empty? lst)]
    [(eq? (car lst) act)true])
    [else  false])

(define (pack lst)
  (cond
    [(empty? lst)  '()]
    [(empy?(actual (car lst) cr(lst)))]
    [else '()]))